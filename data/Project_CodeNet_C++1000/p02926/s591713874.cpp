#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;

int main(){
    int n;
    cin >> n;
    long double ans=0;
    vector<long long> x(n),y(n);
    rep(i,n){
        cin >> x.at(i) >> y.at(i);
    }
    rep(i,n){
        long long a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
        long long aa=0,bb=0,cc=0,dd=0,ee=0,ff=0,gg=0,hh=0;
        long long u=-x.at(i),o=y.at(i);
        rep(j,n){
            if (o*x.at(j)+u*y.at(j)>=0) {
                c+=x.at(j);d+=y.at(j);
                if (o*x.at(j)+u*y.at(j)==0){
                if (x.at(i)*x.at(j)>0 || y.at(i)*y.at(j)>0) {g+=x.at(j);h+=y.at(j);}
                else {e+=x.at(j);f+=y.at(j);}
                }
                else {g+=x.at(j);h+=y.at(j);e+=x.at(j);f+=y.at(j);}
                }
            if (o*x.at(j)+u*y.at(j)>0) {
                a+=x.at(j);b+=y.at(j);
            }
            if (o*x.at(j)+u*y.at(j)<=0) {
                cc+=x.at(j);dd+=y.at(j);
                if (o*x.at(j)+u*y.at(j)==0){
                if (x.at(i)*x.at(j)>0 || y.at(i)*y.at(j)>0) {gg+=x.at(j);hh+=y.at(j);}
                else {ee+=x.at(j);ff+=y.at(j);}
                }
                else {gg+=x.at(j);hh+=y.at(j);ee+=x.at(j);ff+=y.at(j);}
                }
            if (o*x.at(j)+u*y.at(j)<0) {
                aa+=x.at(j);bb+=y.at(j);
                
            }
        }
        
        long double t=sqrt(a*a+b*b),tt=sqrt(c*c+d*d),r=sqrt(e*e+f*f),rr=sqrt(g*g+h*h);
        long double t1=sqrt(aa*aa+bb*bb),tt1=sqrt(cc*cc+dd*dd),r1=sqrt(ee*ee+ff*ff),rr1=sqrt(gg*gg+hh*hh);
        ans=max(ans,t);ans=max(ans,tt);ans=max(ans,r);ans=max(ans,rr);
        ans=max(ans,t1);ans=max(ans,tt1);ans=max(ans,r1);ans=max(ans,rr1);
    }
    cout << fixed << setprecision(13) << ans << endl;
}
