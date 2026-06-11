#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define ff first
#define ss second
#define p pair<int,int>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define pi acos(-1)
const int mod=998244353;
int main()
{
    fast;
    double a,b,h,m;
    cin>>a>>b>>h>>m;
    double degh=(((h*360)/12)+((m*30)/60))*(pi/180.0);
    double degm=(m*6)*(pi/180.0);
    //cout<<degh<<" "<<degm<<endl;
    double hx=a*cos(degh);
    double hy=a*sin(degh);
    double mx=b*cos(degm);
    double my=b*sin(degm);
    double ans=sqrt(pow((hx-mx),2)+pow((hy-my),2));
    cout<<fixed<<setprecision(20)<<ans<<endl;
}
