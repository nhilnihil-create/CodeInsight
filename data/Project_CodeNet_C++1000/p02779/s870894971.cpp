#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<int,int>m;
    lli n;
    cin>>n;
    lli a[n],i,flag=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
        if(m[a[i]]>1)
         flag=1;
    }
    if(flag==1)
     cout<<"NO"<<"\n";
     else
       cout<<"YES"<<"\n";
}