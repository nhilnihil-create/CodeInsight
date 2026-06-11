#include<bits/stdc++.h>
using namespace std;

int main()
{

    long long n,m,i,j,k,a,b,c,sz,az,st,x,y,z;
    vector<long long>v,ans;

    vector<long long>::iterator it;

    string str;

    scanf("%lld %lld",&n,&m);

    cin>>str;

    for(i=0;i<n+1;i++)
    {
        if(str[i]=='0')
        {
            v.push_back(i);
        }
    }

    st=n;

    while(1)
    {

        y=max(0LL,st-m);

        it=lower_bound(v.begin(),v.end(),y); x=it-v.begin(); z=v[x];

        if(z==st)break;
        else
        {
            ans.push_back(st-z); st=z;   if(st==0)break;

        }


    }

    if(st!=0)printf("-1\n");
    else
    {
        sz=ans.size();

        for(i=sz-1;i>=0;i--)
        {
            printf("%d ",ans[i]);
        }

    }



    return 0;
}
