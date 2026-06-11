#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,n;
    cin>>x>>n;
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        m[a]=1;
    }
    int ans=5000;
    for(int i=0;i<200;i++)
    {
        int t1=x-i,t2=x+i;
        if(m[t1]==0)
        {
            ans=t1;
            break;
        }
        if(m[t2]==0)
        {
            ans=t2;
            break;
        }
    }
    cout<<ans;
  	return 0;
}





