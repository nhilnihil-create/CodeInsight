#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
const int N=2e5+3;
string s,p;
int main()
{
    ft
    ll t,i,j,n,m,l=0,r,x;
    cin>>s>>p;
    n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]==p[i])
        {
            l++;
        }
    }
    cout<<l<<"\n";
    return 0;
}

