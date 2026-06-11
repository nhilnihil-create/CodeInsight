#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;

    map<string,ll> mp;
    string str;
    string al = "abcdefghijklmnopqrstuvwxyz";

    rep(i,n){        
        string str2;
        vector<int> vec(26,0);
        cin >> str;
        rep(j,10){
            vec[(int)(str[j]-'a')]++;
        }

        rep(j,26){
            rep(k,vec[j]){
                str2 += al[j];
            }
        }
        mp[str2]++;
    }
    ll ans = 0;
    for(auto e: mp){
        ans += e.second * (e.second -1)/2;
        //cout << e.first << " " << e.second << endl;
    }
    cout << ans << endl;

    return 0;
}