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
    int n,d;
    cin >> n >>d;
    int cnt=0;
    vector<vector<int>> a(n,vector<int> (d));
    rep(i,n) rep(j,d) cin >> a[i][j];
    rep(i,n-1){
        for(int j=i+1;j<n;j++){
            int ans=0;
            rep(k,d){
                ans+=(a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
            }
            if((int)sqrt(ans)==sqrt(ans)){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}