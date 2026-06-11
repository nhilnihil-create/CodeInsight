#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll factorial(ll n){
    if(n ==0) return 1;
    else return n * factorial(n-1);
}

vector<int> make_map(string s){
    vector<int> c(26);
    for(int i=0;i<s.size();i++){
        int n = s.at(i) - 'a';
        c.at(n)++;
    }
    return c;
}

int main(){
    int n;
    cin >> n;
    map<string,ll> m;
    ll count = 0;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        if(m.count(s)){
            m[s]++;
        }else{
            m[s] = 1;
        }
    }

    for(auto p:m){
        //cout << p.second << endl;
        if(p.second>1){
            count += p.second * (p.second - 1) / 2;
        }
    }
    cout << count << endl;    
}