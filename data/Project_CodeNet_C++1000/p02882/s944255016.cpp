#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll a,b,x;
    double ans;
    cin>>a>>b>>x;
    if(2*x>a*a*b){
        ans=180*atan((double)(2.0*(a*a*b-x)/(a*a*a)))/pi;
    }else{
        ans=90-180*atan((double)(2.0*x)/(a*b*b))/pi;
    }
    cout << std::fixed << std::setprecision(15) << ans << endl;
}