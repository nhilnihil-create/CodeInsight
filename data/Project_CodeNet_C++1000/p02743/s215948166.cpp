#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=998244353;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans1=a*b*4;
    ll ans2=(c-a-b)*(c-a-b);
    if(ans1<ans2&&c>(a+b))
        cout<<"Yes"<<'\n';
    else
        cout<<"No"<<'\n';











}
