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
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    ll ans=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int v=1;v<=k;v++){
                ans+=gcd(i,gcd(j,v));
            }
        }
    }
    cout << ans;

    return 0;
}