//---------------------------------------------------------------
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
//---------------------------------------------------------------
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1000000000000000LL
#define all(x) x.begin(),x.end()
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
int n,m,q;
vec a,b,c,d;
int ans;

void dfs(vec A){
   if(A.size()==n+1){
    int now=0;        
        rep(i,q){
            if(A[b[i]] - A[a[i]] == c[i]) now+=d[i];

        }
    ans = max(ans, now);     
    return;       
    }

    A.push_back(A.back());    
    while(A.back()<=m){
        dfs(A);
        A.back()++;        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin>>n>>m>>q;
    a = b = c = d =vec(q);
    rep(i,q){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    dfs(vec(1,1));

    cout<<ans<<endl;
    return 0;
}