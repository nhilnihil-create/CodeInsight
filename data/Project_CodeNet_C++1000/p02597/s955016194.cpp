#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_I_O ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9+7 , INF = 1e9 ,  mx = 100005 ;
main()
{
    fast_I_O;
    int i,j,n,m,x,y,sum=0,p=0,l,k;
    cin>>n;
    string s;
    cin>>s;
    i=0 , j=n-1;
    while(i<j)
    {
        if(s[i]=='W' && s[j]=='R') ++p , ++i , --j;
        if(s[i]=='R') ++i;
        if(s[j]=='W') --j;
    }
    cout<<p;
    return 0;
}