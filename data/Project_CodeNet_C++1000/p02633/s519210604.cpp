#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi 3.14159265358979323846
#define mod 1000000007
int main()
{
    IOS;
    ll a,b,c,d,e=0;
    cin>>a;
    b=a;
    while(b!=0)
    {
        b=b+a;
        b=b%360;
        e++;
    }
    cout<<e+1<<endl;
}