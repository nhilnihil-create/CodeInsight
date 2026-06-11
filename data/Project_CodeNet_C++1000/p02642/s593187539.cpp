#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<int,int> m;
int fun(int n)
{
    int flag=0;
    m[n]--;
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            int one=i;
            int two=n/i;
            //cout<<one<<" "<<two<<endl;
            if((m[one]>0))
                flag=1;
            if((m[two]>0))
                flag=1;
        }
    }
    m[n]++;
    if(flag)
    {
        //cout<<"hey"<<endl;
        return 0;
    }
    return 1;
}
int main()
{
    int  n,ar[200007];
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int val;
        scanf("%d",&val);
        m[val]++;
        ar[i]=val;
    }
    int mh=0;
    for(int i=1; i<=n; i++)
    {
        mh=mh+fun(ar[i]);
    }
    printf("%d\n",mh);
    return 0;
}
