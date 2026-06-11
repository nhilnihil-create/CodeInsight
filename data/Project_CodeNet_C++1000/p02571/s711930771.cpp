#include<bits/stdc++.h>
#define ll long long
#define debug(x) {cerr<<#x<<" = "<<(x)<<endl;}
#define M(x) memset(x,0,sizeof(x))
#define dalao main
using namespace std;
int same(string x,string y)
{
    int sum=0;
    for(int i=0;i<x.size();i++)
        sum+=(x[i]==y[i]);
    return sum;
}
int dalao()
{
    string s,t;//let t be substring of s
    cin>>s>>t;
    int ls=s.size(),lt=t.size();
    int ans=lt;
    for(int i=0;i+lt<=ls;i++)
    {
        string sub=s.substr(i,lt);
        ans=min(ans,lt-same(sub,t));
    }
    cout<<ans<<endl;
    return 0;
}
