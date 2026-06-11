#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    double a,b,x;
    cin>>a>>b>>x;
    double v=a*a*b;
    double ans;
    double rest=v-x;
    double pi=3.141592653589;
    if(v<2*x){
        ans=atan2(2*rest,pow(a,3));
        //cout<<1<<endl;
    }else{
        ans=atan2(a*b*b,2*x);
    }
    cout<<fixed<<setprecision(12)<<ans*180/pi<<endl;
}