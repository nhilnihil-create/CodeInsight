#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main()
{
    ll n,m,i,a=0,b=0,k,t,j;
    string s1,s2;
    string s;
    cin>>n>>s1>>s2;
    for(i=0;i<s1.size();i++)
    {
        s.pb(s1[i]);
        s.pb(s2[i]);
    }
    cout<<s;
}