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
    vector<string> a(n);
    rep(i,n){
        string m;
        cin >> m;
        sort(m.begin(),m.end());
        a[i]=m;
    }
    sort(a.begin(),a.end());
    ll cnt = 1;
    ll ans = 0;
    rep(i,n-1){
        if(a[i]==a[i+1]){
            cnt++;
            // cout << cnt << endl;
        }
        else{
            // cout << cnt << " " << i << endl;
            ans += cnt*(cnt-1)/2;
            cnt = 1;
        }
    }
    ans += cnt*(cnt-1)/2;
    cout << ans;

    return 0;
}