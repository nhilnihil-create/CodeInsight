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
    vector<int> b(n-1);
    rep(i,n-1){
        cin >> b[i];
    }
    a[0]=b[0];
    a[n-1]=b[n-2];
    for(int i=1;i<n-1;i++){
        a[i]=min(b[i-1],b[i]);
    }
    int sum=0;
    rep(i,n){
        sum+=a[i];
    }
    cout << sum;
    return 0;
}