#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 110000
ll MOD=1e9+7;
const int MAX_ROW = N; // to be set appropriately
const int MAX_COL = 64; // to be set appropriately
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
};

int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; ++row) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}
main(){
    int n=in();
    vecll v;
    rep(i,n){
        v.pb(lin());
    }
    ll sum=0;
    rep(i,n){
        sum^=v[i];
    }
    //cout<<sum<<endl;
    int m=0;
    ll ans=0;
    vector<ll> mem;
    rep3(i,59,0){
        ll t=(1ll<<i);
        if((t&sum)==0){
            mem.pb(t);
            m++;
            //cout<<t<<endl;
        }
        else{
            ans+=t;
        }
    }

    BitMatrix bm(n,m);
    rep(i,n)rep(j,m){
        if(v[i]&mem[j])bm[i][j]=1;
    }
    GaussJordan(bm);
    int pre=0;
    rep(j,m){
        bool f=0;
        rep(i,n){
            f^=bm[i][j];
        }
        if(f)ans+=mem[j]*2ll;
    }
    cout<<ans<<endl;
}