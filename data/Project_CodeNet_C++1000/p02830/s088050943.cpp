#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define ll long long
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define val 1000000000000000000
using namespace std;
int main()
{
    ll n;
    cin>>n;
    char s1[n],s2[n];
    cin>>s1>>s2;
    char s[2*n];
    ll j=0;
    for(int i=0;i<n;i++)
    {
        s[j++]=s1[i];
        s[j++]=s2[i];
    }
    for(int i=0;i<2*n;i++)
    cout<<s[i];
    cout<<endl;
}
