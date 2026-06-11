#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>
//#include <bits/stdc++.h>
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=2147483647;
const ll LLMAX=9223372036854775807;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll A,B,M;
    cin>>A>>B>>M;
    vll a(A),b(B);
    for(ll i=0;i<A;i++)cin>>a[i];
    for(ll i=0;i<B;i++)cin>>b[i];
    vll x(M),y(M),c(M);
    for(ll i=0;i<M;i++){
        cin>>x[i]>>y[i]>>c[i];
        x[i]--;y[i]--;
    }
    
    ll ans=LLMAX;
    for(ll i=0;i<M;i++){
        chmin(ans,a[x[i]]+b[y[i]]-c[i]);
    }
    sort(ALL(a));
    sort(ALL(b));
    chmin(ans,a[0]+b[0]);
    cout<<ans<<endl;
    
    return 0;
}
