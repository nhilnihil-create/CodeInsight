#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t,l;
    string s;
    ll c,d,cd;
    cin>>a>>b>>c>>d;
    ll divc,divd,divcd;
    divc=b/c;
    divc-=a/c;
    if(a%c==0) divc++;
    divd=b/d;
    divd-=a/d;
    if(a%d==0) divd++;
    cd=(c*d)/__gcd(c,d);
    divcd=b/cd;
    divcd-=a/cd;
    if(a%cd==0) divcd++;
    ll rem=divc+divd-divcd;
    ll ans=b-a+1;
    ans-=rem;
    cout<<ans;
    
}