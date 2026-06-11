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
    rep(i,n+1) cin >> a[i];
    ll ans=0;
    rep(i,n){
        int m;
        cin >> m;
        if(m<=a[i]) {
            ans+=m;
            // cout << ans << endl;
        }
        else{
            if(m-a[i]<=a[i+1]){
                a[i+1]-=m-a[i];
                ans+=m;
                // cout << ans << endl;
            }
            else{
                ans+=a[i]+a[i+1];
                a[i+1]=0;
                // cout << ans << endl;
            }
        }
    }
    cout << ans;

    return 0;
}