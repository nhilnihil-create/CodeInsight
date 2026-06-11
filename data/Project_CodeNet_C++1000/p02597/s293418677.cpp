#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
bool ar[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,t,n,b,a,c,d,l,rr;
    cin>>n;
    string s;
    cin>>s;
    ll r=0,cnt=0;
    for(i=0; i<n; i++)
        if(s[i]=='R')
            r++;
    for(i=0; i<r; i++)
        if(s[i]=='W')
            cnt++;
    cout<<cnt<<'\n';
}









