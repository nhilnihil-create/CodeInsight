#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int a,b,x; cin>>a>>b>>x;

    double theta;
    if(a*a*b/2.>=x){
        double d=2.*x/b/a;
        theta=atan(b/d);
    }else{
        double _b=2*b-2.*x/a/a;
        theta=atan(_b/a);
    }

    theta=theta*180/(2*acos(0));
    cout<<fixed<<setprecision(10)<<theta<<endl;
}