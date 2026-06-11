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
#include<algorithm>
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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,x,y;
    cin>>n>>x>>y;
    --x;--y;
    vector<vector<int>> dist(n,vector<int>(n,-1));
    rep(i,n){
        queue<int> q;
        q.push(i);
        dist[i][i]=0;

        while(!q.empty()){
            int v=q.front();
            q.pop();
            vector<int> nvi;            
            if(v>0) nvi.push_back(v-1);
            if(v<n-1) nvi.push_back(v+1);
            if(v==x) nvi.push_back(y);
            if(v==y) nvi.push_back(x);
            for(auto nv: nvi){
                if(dist[i][nv]!=-1) continue;
                dist[i][nv] = dist[i][v] + 1;
                q.push(nv); 
            }
        }
    }

    vec cnt(n,0);
    rep(i,n)for(int j=i+1;j<n;j++){
        cnt[dist[i][j]]++;
    }

    rep1(i,n-1){
        cout<<cnt[i]<<endl;
    }


}