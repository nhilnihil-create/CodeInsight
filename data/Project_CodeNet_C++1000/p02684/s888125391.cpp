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
#define fi first
#define se second
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

    ll n,k;
    cin>>n>>k;
    vll a(n+1);
    rep1(i,n){
        cin>>a[i];
    }

    int cnt=0;
    vector<pint> ed(n+1);

    int roop;

    int cur=a[1];
    ed[1].fi++;
    ed[1].se=cnt;

    rep1(i,n){
        cnt++;
        ed[cur].fi++;
        ed[cur].se=cnt;
        cur=a[cur];
        if(ed[cur].fi>=1){
            cnt++;
            roop = cnt - ed[cur].se;
            break;
        }
    }

    
    if(k <= cnt){
        int cur2=1;
        rep(i,k){
            cur2=a[cur2];
        }
        cout<<cur2<<endl;
        return 0;
    }else{
        k -= cnt;
        k%=roop;
        int cur2=1;
        rep(i,k+cnt){
            cur2=a[cur2];
        }
        cout<<cur2<<endl;
        return 0;
    }

}