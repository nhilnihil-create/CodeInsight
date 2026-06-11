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
    x/=a;
    
    if(a*b>=2*x){
        double y=2*x/b;
        double ans=atan(b/y);
        ans=ans*180/pi;
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    else{
        double y=(2*x-a*b)/a;
        double ans=atan((b-y)/a);
        ans=ans*180/pi;
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }

    
}

