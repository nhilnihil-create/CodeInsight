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
    int t,i,j,n,m=INT_MAX,l=0,r=0,a[105];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        l+=a[i];
    }
    for(i=0;i<n-1;i++)
    {
        r+=a[i];
        l-=a[i];
        m=min(m,abs(l-r));
    }
    cout<<m<<"\n";
    return 0;
}

