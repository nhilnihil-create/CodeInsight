#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vl vector
using namespace std;

int main()
{
    ll t,i,n;
    ll a,b,c;
    string s1,s2;
    cin>>s1>>s2;
    cin>>a>>b;
    string rem;
    cin>>rem;
    if(s1==rem) a--;
    if(s2==rem) b--;
    cout<<a<<" "<<b;
}