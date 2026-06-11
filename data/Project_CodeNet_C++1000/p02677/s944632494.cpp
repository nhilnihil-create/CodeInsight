#include<bits/stdc++.h>
using namespace std;
double PI=2.0*acos(0.0);
double hc=180.0;
int main(){
        int a,b,c,d; cin>>a>>b>>c>>d;
        auto sqr=[&](int a){return (double)a*a; };
        c=c*60+d;
        double hh=c/(double)2;
        double mh=d*6.0;
        double dhm=fabs(hh-mh);
        dhm=min(dhm,360-dhm);
        double dist=sqr(a)+sqr(b)-2.0*a*b*cos((PI*dhm)/hc);
        cout<<fixed<<setprecision(10)<<sqrt(dist)<<endl;
}

