#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

int main() {
 ll s ;
 cin>> s ;
 ll mod =1e9 ;
 ll n = s/mod ;
 ll k= s%mod ;
if(s== 1e18)
cout <<0<<" "<<0<<" "<<0<<" "<<mod<<" "<<mod<<" "<<0<<endl;
else
cout <<n<<" "<<0<<" "<<0<<" "<<k<<" "<<n+1<<" "<<mod<<endl ; 
    return 0;
}