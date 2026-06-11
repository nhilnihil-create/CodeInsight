#include<bits/stdc++.h>
using namespace std;
string s;
int a[200005],b[200005];
int main()
{
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    int n,k,c,jqs=1;
    cin>>n>>k>>c>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='o'){a[i+1]=jqs;i+=c;jqs++;}
        if(jqs>k)break;
    }
    jqs--;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='o'){b[i+1]=jqs;i-=c;jqs--;}
        if(jqs==0)break;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]&&b[i]&&a[i]==b[i])cout<<i<<endl;
    }
    return 0;
}