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
    int now=0;
    int ans=0;
    int cnt=0;
    rep(i,n){
        int m;
        cin >> m;
        if(now<m){
            ans=max(ans,cnt);
            now = m;
            cnt=0;
        }
        else{
            ++cnt;
            now = m;
        }
    }
    ans = max(ans,cnt);
    cout << ans;
    return 0;
}