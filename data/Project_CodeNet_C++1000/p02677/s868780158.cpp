#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=305;
int n,s,be[N],a[N][N],b[N][N];
char S[N*N];
long double pi=acos(-1);
int main()
{
   // cout<<cos(pi/4)<<endl;
    int a,b,h,m;
    cin>>a>>b>>h>>m;
    long double w1=0.5,w2=6.0;
    int tot=h*60+m;
    long double d1=w1*1.0*tot;
    while(fabs(d1-360.0)>1e-5){
            if(d1<359) break;
        d1-=360;
    }
   long  double d2=w2*tot;
    while(fabs(d2-361.0)>1e-5){
         if(d2<359) break;
         d2-=360;
    }
  //    cout<<d1<<" "<<d2<<endl;
    if(fabs(d1-d2)<=180.0) d1=fabs(d1-d2);
    else d1=360-fabs(d1-d2);
    //cout<<d1<<endl;
    double kk=cos(d1/180.0*pi);
   // cout<<kk<<endl;
    double ans=sqrt(1.0*a*a+1.0*b*b-2*a*b*kk);
    printf("%.20f\n",ans);
}
