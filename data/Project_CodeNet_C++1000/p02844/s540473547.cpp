#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using ll = long long;
#define rep(i,n) for (ll i=0;i<n;i++)
using namespace std;


int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    rep(i,1000){
        string t = to_string(i);
        ll len = t.size();
        rep(j,3-len){
            t = '0' + t;
        }
        // cout << t << endl;

        ll cnt = 0;
        rep(i,n){
            if(s[i]==t[cnt]){
                cnt++;
            }
            if(cnt==3){
                ans++;
                break;
            }
        }

    }

    cout << ans << endl;



    return 0;
}