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
    int ans=10000000;
    rep(i,n){
        int sum1=0,sum2=0;
        rep(j,i+1){
            sum1+=a[j];
        }
        for(int k=i+1;k<n;k++){
            sum2+=a[k];
        }
        ans=min(ans,abs(sum2-sum1));
    }
    cout << ans;

    return 0;
}