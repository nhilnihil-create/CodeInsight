#include <bits/stdc++.h>
using namespace std;
const long long int MOD = (1LL<<31) - 1;
const long long int base1 = 48271;
const long long int base2 = 69621;

bool contain(string a, string b, long long int BASE){// find a from b
    if(a.length() > b.length()) return false;

    long long int powB = 1;
    for(int i=0; i<a.length(); i++){
        powB *= BASE;
        powB %= MOD;
    }

    // Hash
    long long int hash_a = 0;// a[0] * BASE^(la-1) + ... + a[la-2] * BASE + a[la-1] 
    long long int hash_b = 0;
    for(int i=0; i<a.length(); i++){
        hash_a = hash_a * BASE + a[i];
        hash_b = hash_b * BASE + b[i];// hash of b.substr(0, a.length())

        hash_a %= MOD;
        hash_b %= MOD;
    }

    // Roll
    for(int i=0; i+a.length()<=b.length(); i++){
        if(hash_a == hash_b) return true;// b.substr(i,la) == a
        else if(i + a.length() < b.length()){
            hash_b = hash_b * BASE + b[i+a.length()] - b[i] * powB;
            hash_b = (hash_b % MOD + MOD) % MOD;
        }
    }
    return false;// i + a.length() == b.length() : coudln't find
}

int main(){
    int n;
    string s;
    cin >> n >> s;

    int upper = n, lower = 0, mid;
    while(upper - lower > 1){
        mid = (upper + lower) / 2;
        //cout << mid << endl;
        bool flag = false;
        for(int i=0; i+2*mid<=n; i++){
            string word = s.substr(i,mid);
            //cout << word << " " << s.substr(i+mid) << endl;
            if(contain(word, s.substr(i+mid), base1) == true
            && contain(word, s.substr(i+mid), base2) == true){
                flag = true;
                lower = mid;
                break;
            }
        }
        if(flag == false) upper = mid;
    }
    cout << lower << endl;
    return 0;
}