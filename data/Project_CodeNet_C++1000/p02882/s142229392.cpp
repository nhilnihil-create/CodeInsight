#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

double pi=acos(-1);

int main(){
    double a,b,x;
    cin>>a>>b>>x;

    if(2*x>a*a*b){
        double z=2*b-2*x/(a*a);
        double s=atan(a/z);
        double ans=s*180/pi;
        ans=90-ans;
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    else{
        double y=2*x/(a*b);
        double s=atan(y/b);
        double ans=s*180/pi;
        ans=90-ans;
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }

}
