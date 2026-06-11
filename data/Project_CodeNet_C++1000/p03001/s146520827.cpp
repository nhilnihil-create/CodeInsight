#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

ll w,h,x,y;

int main(){
    cin>>w>>h>>x>>y;
    int ans;
    if(w/2.0==x && h/2.0==y) ans=1;
    else ans=0;
    cout<<fixed<<setprecision(12)<<h*w/2.0<<" "<<ans<<"\n";
    return 0;
}
