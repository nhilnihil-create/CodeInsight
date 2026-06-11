#include <bits/stdc++.h>
using namespace std;

int main(){
    map<long long, long long> mp;
    long long K, tmp = 1, a = 7;
    cin >> K;
    while(1){
        a %= K;
        //cout << a << endl;
        if(a == 0) break;
        else if(mp[a] == 0){
            mp[a]++;
            a = a * 10 + 7;
            tmp++;
        }
        else{
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << tmp << endl;
    return 0;
}
