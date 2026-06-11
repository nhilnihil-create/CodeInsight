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
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<int> b(n+1);
    a[0] = 1;
    a[1] = 1;
    rep(i,m){
        int q;
        cin >> q;
        b[q] = 1;
    }
    if(b[1]==1){
        a[1] = 0;
    }
    for(int i=2;i<n+1;i++){
        if(b[i]==0){
            a[i] = a[i-1] + a[i-2];
            a[i] %= 1000000007;
        }else{
            a[i] = 0;
        }
    }
    cout << a[n];
    return 0;
}