#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
#define  B   begin()
#define  E   end()
const int N=2e5+3;
string s,p;
//vector<int>v;
//map<int,int>mp;

int main()
{
    ft
    ll t,i,j,n,m,l,r,x,y;
    cin>>n>>m>>l>>r;
    x=m/l - (n-1)/l;
    y=m/r -(n-1)/r;
    ll p=(l*r)/__gcd(l,r);
    ll q=m/p - (n-1)/p;
    cout<<((m-n+1)-(x+y-q))<<"\n";
    return 0;
}

