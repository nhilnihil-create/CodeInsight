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
    int ans=0;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n-1) cin >> c[i];
    int before = a[0];
    rep(i,n){
        ans+=b[a[i]-1];
        if(a[i]==before+1){
            ans+=c[before-1];
            // cout << c[before-1] <<endl;
        }
        before = a[i];
    }
    cout << ans;

    return 0;
}