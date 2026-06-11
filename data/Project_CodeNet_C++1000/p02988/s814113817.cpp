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
    rep(i,n) cin >> a[i];
    int cnt=0;
    for(int i=1;i<n-1;i++){
        if(a[i]!=max({a[i-1],a[i],a[i+1]})&&a[i]!=min({a[i-1],a[i],a[i+1]})) cnt++;
    }
    cout << cnt;


    return 0;
}