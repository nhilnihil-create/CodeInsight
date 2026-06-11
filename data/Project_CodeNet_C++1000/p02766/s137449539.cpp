#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,t,n,b,c,d,a,l,r;
    cin>>n>>m;
    ll cnt=0;
    while(n)
    {
        cnt++;
        n/=m;
    }
    cout<<cnt<<'\n';
}












