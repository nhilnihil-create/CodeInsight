//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.second<b.second);
}
const long double PI=(acos(-1));
const long double EPS=0.0000000001;
long double a,b,x;
long double f(long double a,long double b,long double x)
{
    long double ans;
    if(a*a*b/2.0<=x)
        ans=atan(2*(a*a*b-x)/(a*a*a));
    else
        ans=PI/2-atan(2*x/(a*b*b));
    return ans;
}
int main()
{
    cin>>a>>b>>x;
    cout<<fixed<<setprecision(10)<<f(a,b,x)*180.0/PI<<endl;
}

















