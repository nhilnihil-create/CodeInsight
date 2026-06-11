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
    int n,x;
    cin >> n >> x;
    int cnt=1;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    int now=0;
    for(int i=1;i<n+1;i++){
        if(now+a[i-1]<=x){
            cnt++;
            now+=a[i-1];
        }
        else{
            break;
        }
    }
    cout << cnt ;

    return 0;
}