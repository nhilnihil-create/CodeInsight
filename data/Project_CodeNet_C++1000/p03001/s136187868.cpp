#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;
 
int main(){
    double w,h,x,y;
    cin>>w>>h>>x>>y;

    double ans=w*h/2;
    cout<<fixed<<setprecision(10)<<ans<<" ";

    if(2*x==w && 2*y==h) cout<<1<<endl;
    else cout<<0<<endl;
}