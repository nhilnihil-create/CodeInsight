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
long double f(long double a,long double b,long double theta)
{
    if(theta>PI/2.0-EPS)
        return 0.0;
    long double ret;
    if(a*tan(theta)<=b)
        ret=a*a*b-a*a*a*tan(theta)/2.0;
    else
        ret=b*b/tan(theta)*a/2.0;
    return ret;

}
int main()
{
    cin>>a>>b>>x;
    long double ok=PI/2.0;
    long double ng=0.0;
    for(int i=1;i<=10000;i++)
    {
        long double mid=(ok+ng)/2.0;
        if(f(a,b,mid)<x)
            ok=mid;
        else
            ng=mid;
    }
    cout<<fixed<<setprecision(10)<<ok/PI*180<<endl;
}

















