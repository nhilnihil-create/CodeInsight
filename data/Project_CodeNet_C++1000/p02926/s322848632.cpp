#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
double dis(double xa,double ya,double xb,double yb){
    return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    double x[200001],y[200001],pi=3.14159265358979;
    cin>>n;
    rep(i,n) cin>>x[i]>>y[i];
    vector<pair<double,int>> A;
    rep(i,n){
        double a;
        if(x[i]==0) a=pi/2;
        else a=atan(y[i]/x[i])+(atan(y[i]/x[i])<0)*pi;
        if(y[i]<0) a+=pi;
        if(y[i]==0&&x[i]<0) a+=pi;
        A.push_back(make_pair(a,i));
    }
    sort(all(A));
    double ans=0;
    rep(i,n)for(int j=i;j<n+i;j++){
        double X=0,Y=0;
        for(int k=i;k<=j;k++) X+=x[A[k%n].second],Y+=y[A[k%n].second];
        ans=max(ans,dis(0,0,X,Y));
    }
    cout<<setprecision(11)<<ans<<"\n";
}