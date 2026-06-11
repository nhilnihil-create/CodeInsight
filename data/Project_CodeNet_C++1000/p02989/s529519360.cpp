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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    ll cnt=0;
    if(a[n/2]==a[n/2-1]){
        cout << 0;
        return 0;
    }else{
        cout << a[n/2]-a[n/2-1];
    }
        
    

    return 0;
}