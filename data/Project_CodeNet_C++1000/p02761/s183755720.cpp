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
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n,m;cin>>n>>m;
        vec s(m);
        vec c(m);    
    rep(i,m){
        cin>>s[i]>>c[i];
    }
    rep(i,m) --s[i];

    for(int i=0;i<=pow(10,n);i++){
        bool ans = true;        
        string num = to_string(i);             
        if(num.size()!=n) continue;
        rep(j,m){
            if(num[s[j]]-'0'!= c[j]){
                ans=false;
            }
        }

        if(ans){
            cout<<i<<endl;
            return 0;
    }

    }

    cout<<"-1"<<endl;
    return 0;
}