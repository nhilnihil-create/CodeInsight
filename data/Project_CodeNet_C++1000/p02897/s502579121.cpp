#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long int
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define vali 1000000000000000000
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    if(n%2==0)
    {
        cout<<"0.5000000000"<<endl;
    }
    else
    {
        ll s=n/2;
        l ss=n-s;
        l ans=ss/n;
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
}