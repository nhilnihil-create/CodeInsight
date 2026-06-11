///-BISMILLAHIR RAHMANIR RAHIM-///
/*Author : Naheen Mohammad Kadir (A LOOSER)*/
/***********************************************/
/*Dear online judge:
* I've read the problem, and tried to solve it.
* Even if you don't accept my solution, you should respect my effort.
* I hope my code compiles and gets accepted. {IN SHAA ALLAH<3}
*      |\          |
*      | \         |
*      |  \        |
*      |   \       |
*      |    \      |
*      |     \     |AHEEN
*      |      \    |
*      |       \   |
*      |        \  |
*      |         \ |
*      |          \|
*/
#include <bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
#define pb push_back
#define scn(n) scanf("%lld",&n)
#define pi acos(-1)
#define ll long long
#define llu unsigned long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
int main()
{
    fast;
    ll t;
    cin>>t;
    vector<ll>x(t),y(t);
    ll i,j,k;
    double d1=0,d2=0,d3=0,d_in=0;
    for(i=0; i<t; i++)
    {
        cin>>x[i];
    }
    for(i=0; i<t; i++)
    {
        cin>>y[i];
    }
    for(i=0; i<t; i++)
    {
        d1+=fabs(x[i]-y[i]);
        d2+=fabs(x[i]-y[i])*fabs(x[i]-y[i]);
        d3+=fabs(x[i]-y[i])*fabs(x[i]-y[i])*fabs(x[i]-y[i]);
        d_in=max(d_in,fabs(x[i]-y[i]));
    }
    cout<<setprecision(13)<<d1<<endl;
    cout<<setprecision(13)<<sqrt(d2)<<endl;
    cout<<setprecision(13)<<cbrt(d3)<<endl;
    cout<<setprecision(13)<<d_in<<endl;
    return 0;
}

