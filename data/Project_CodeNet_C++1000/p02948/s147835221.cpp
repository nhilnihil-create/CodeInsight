#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1000000000000000LL
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<vector<int>> p(m+1);
    rep(i,n){
        int a,b;cin>>a>>b;
        if(a>m) continue;
        p[a].push_back(b);
    }

    priority_queue<int> q;
    
    int ans=0;
    for(int i = 1; i <=m; i++){
    
    for(int x : p[i]){
        q.push(x);
    }

        if(!q.empty()){
            ans+=q.top();
            q.pop();
        }
    }

    cout<<ans<<endl;
    return 0;

}