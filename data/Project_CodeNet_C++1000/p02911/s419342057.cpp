#include <bits/stdc++.h>
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
using namespace std;
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

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k,q;
    cin>>n>>k>>q;
    vec a(q);
    rep(i,q) cin>>a[i];

    vector<int> b(n,k-q);
    rep(i,q) b[a[i]-1]++;

    rep(i,n){
        if(b[i]>0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}