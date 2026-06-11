#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    cout << fixed << setprecision(20);
    double a,b,h,m;
    cin>>a>>b>>h>>m;
    double rad=abs((h+m/60)/12-m/60)*M_PI*2;
    double ans=sqrt(a*a+b*b-2*a*b*cos(rad));
    cout<<ans<<endl;
}