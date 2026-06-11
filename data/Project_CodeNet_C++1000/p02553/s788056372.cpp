#include <bits/stdc++.h>
using namespace std;
#define   nl   <<'\n'
#define   ll   long long
#define   pb   push_back
#define   eb   emplace_back
#define   tc   int t; cin>>t; while(t--)
#define   fio  ios_base::sync_with_stdio(0); cin.tie(0)


int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max(a*c,max(a*d,max(b*c,b*d))) nl;
}   