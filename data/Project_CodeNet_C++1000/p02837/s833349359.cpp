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
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;



void solve(){
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<pair<int,int>>> q(n);
    rep(i,n){
        cin >> a[i];
        rep(j,a[i]){
            int x,y;
            cin >> x >> y;
            q[i].push_back(make_pair(x,y));
        }
    }
    int ans = 0;
    for(int bit=0;bit<(1<<n);bit++){
        int cnt=0;
        bool rr = false;
        rep(i,n){
            if(bit & (1 << i)){
                rep(j,a[i]){
                    int l = q[i][j].first;
                    int r = q[i][j].second;
                    if(r==1){
                        if(bit & (1 << (l-1))) {
                            continue;
                        }else{
                            rr = true;
                            break;
                        }
                    }else{
                        if(!(bit & (1 << (l-1)))) continue;
                        else{
                            rr = true;
                            break;
                        }
                    }
                }
            }
        }
        if(rr){
            continue;
        }else{
            rep(i,n){
                if(bit & (1 << i)) ++cnt;
            }
            ans = max(ans,cnt);
        }
    }

    cout << ans;
    return 0;
}