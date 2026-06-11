#define rep(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;
const long long MOD = (ll)1e9+7;
const long long MAX = (ll)1e5+100;


int main(void) {
   ll N,K;
   cin>>N>>K;
   int a = N - K;
   if (K==1) cout<<0<<endl;
   else cout<<a<<endl;
   return 0;
}