#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

bool check(vector<int> &buy,int x){
    for(int i=1;i<buy.size();i++){
        if(buy[i]<x) return false;
    }
    return true;
}

int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<vector<int>> algo(n,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m+1;j++){
            cin >> algo[i][j];
        }
    }
    int ans=100100100;
    bool flg=false;
    for(int bit=0;bit<(1<<n);bit++){
        vector<int> buy(m+1);
        for(int i=0;i<n;i++){
            if(bit & (1<<i)){
                for(int j=0;j<m+1;j++){
                    buy[j]+=algo[i][j];
                }
            }
        }
        if(check(buy,x)){
            flg=true;
            ans=min(ans,buy[0]);
        }
    }
    if(flg) cout << ans << endl;
    else cout << -1 << endl;
}