#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    double w,h,x,y;
    cin>>w>>h>>x>>y;

    double ans=w*h/2;
    cout<<fixed<<setprecision(12)<<ans<<" ";
    if(w==2*x && h==2*y) cout<<1<<endl;
    else cout<<0<<endl;
}

