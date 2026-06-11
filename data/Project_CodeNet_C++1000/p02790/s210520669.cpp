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
//string s,p;
//vector<int>v;
//map<int,int>mp;

int main()
{
    ft
    ll t,i,j,n,m,l,r;
    cin>>n>>m;
    if(n<m)
    {
        for(i=0;i<m;i++)
        {
            cout<<n;
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            cout<<m;
        }
    }
    return 0;
}

