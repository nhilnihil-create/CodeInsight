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
    int n,l;
    cin >> n >> l;
    int ans=0;
    int m=1000;
    int k;
    for(int i=1;i<n+1;i++){
        if(abs(l+i-1)<m){
            m = abs(l+i-1);
            k = l+i-1;
        }
        ans+=l+i-1;
    }
    cout << ans-k;


    return 0;
}