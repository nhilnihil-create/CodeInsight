#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

double PI=acos(-1);

int main(){
    double a,b,x;
    cin>>a>>b>>x;
    if(a*a*b>=2*x){
        double y=2*x/(a*b);
        double ans=atan(b/y);
        ans=ans*180/PI;
        cout<<fixed<<setprecision(10)<<ans<<endl;
        //cout<<0<<endl;
    }
    else{
        double y=(2*x-a*a*b)/(a*a);
        double ans=atan((b-y)/a);
        ans=ans*180/PI;
        cout<<fixed<<setprecision(10)<<ans<<endl;
        //cout<<1<<endl;
    }
}
