#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n) for(ll i=0;i<(n);i++)
#define For1(i,n) for(ll i=1;i<(n);i++)
int main(void){
    ll n;cin>>n;
    vector<double> x(n),y(n);
    For(i,n) cin>>x.at(i)>>y.at(i);
    double ans=0;
    double p=M_PI/180;
    For(i,360){
        double cosi=cos(i*p),sini=sin(i*p);
        double xi=0,yi=0;
        For(j,n){
            if(cosi*x.at(j)+sini*y.at(j)>=0){
                xi+=x.at(j);
                yi+=y.at(j);
            }
        }
        ans=max(xi*xi+yi*yi,ans);
    }
    cout<<setprecision(12)<<sqrt(ans)<<endl;
}
