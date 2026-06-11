#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

double n,k;
vector<double> p(200100),s(200100);

int main(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>p[i];
        p[i]=(1+p[i])/2.0;
        s[i+1]=s[i]+p[i];
    }
    double ans=0;
    per(i,n,k) chmax(ans,s[i]-s[i-k]);

    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}
