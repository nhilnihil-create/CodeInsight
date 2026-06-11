#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int a,b,x;
    cin>>a>>b>>x;
    double s=(double)x/a;
    double ans;
    double pi=acos(-1);
    if(s<=a*b/2.0){
        double w=2.0*s/b;
        ans=atan2(b,w)*(180/pi);
    }
    else{
        double h=2.0*(a*b-s)/a;
        ans=atan2(h,a)*(180/pi);
    }
    printf("%.10f\n",ans);
    return 0;
}