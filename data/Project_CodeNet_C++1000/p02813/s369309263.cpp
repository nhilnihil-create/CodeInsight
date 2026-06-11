#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    int n,i,a=0,b=0,k1,k2,n1=0,n2=0,ans1,ans2;
    cin>>n;
    int m1[n];
    int m2[n];
    for(i=0;i<n;i++)
    {
        cin>>m1[i];
        n1=n1*10+m1[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>m2[i];
        n2=n2*10+m2[i];
    }
    sort(m1,m1+n);
    sort(m2,m2+n);
    for(i=0;i<n;i++)
    {
        a=a*10+m1[i];
    }
    k1=a;
    for(i=1;i<n;i++)
    {
        b=b*10+m2[i];
    }

    long long fact=1;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    map<int,int>mp1;
    map<int,int>mp2;
    mp1.insert({k1,1});
    for(i=2;i<=fact;i++)
    {
        next_permutation(m1,m1+n);
        a=0;
        for(int j=0;j<n;j++)
        {
            a=a*10+m1[j];
        }
        mp1.insert({a,i});
    }
    for(auto i:mp1)
    {
        if(i.first==n1)
        {
             ans1=i.second;
        }
        if(i.first==n2)
        {
             ans2=i.second;
        }
    }
    cout<<abs(ans2-ans1)<<endl;
    return 0;

}
