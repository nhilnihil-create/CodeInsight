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
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    sort(h.begin(),h.end(),greater<int>());
    
    rep(i,min(n,k)){
        h[i]=0;
    }
    ll sum = 0;
    rep(i,n) sum += h[i];
    cout << sum;

    return 0;
}