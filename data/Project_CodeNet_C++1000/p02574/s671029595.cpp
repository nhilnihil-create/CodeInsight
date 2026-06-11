#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n;

    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    sort(a.begin(),a.end());
    int g=0;
    for(int i=0; i<n; i++)
    {
        g=__gcd(g,a[i]);
        if (g==1)break;
    }
    if(g!=1)
    {
        cout<<"not coprime"<<endl;
    }
    else
    {
        vector<int>d(a[n-1]+1);
        for(int i=1; i<=a[n-1]; i++)d[i]=i;

        for(int i=4; i<=a[n-1]; i+=2)d[i]=2;

        for(int i=3; (long long)i*i<=a[n-1]; i++)
        {
            if(d[i]==i)
            {
                for(int j=i*i; j<=a[n-1]; j+=i)
                {
                    if(d[j]==j)d[j]=i;
                }
            }
        }

        map<int,int>m;
        k=0;
        for(int i=n-1; i>=0; i--)
        {
            int t=a[i];
            if(d[t]==t)
            {
                if(t==1)continue;
                if(m[t])
                {
                    k=1;
                    break;
                }
                else m[t]++;
            }
            else
            {
                for(int j=d[t]; (long long)j*j<=t; j++)
                {
                    if(t%j==0)
                    {
                        if(m[j])
                        {
                            k=1;
                            break;
                        }
                        else m[j]++;
                        while(t%j==0)t/=j;
                    }
                }
                if(t>1)
                {
                    if(m[t])k=1;
                    else m[t]++;
                }
                if(k)break;
            }
        }
        //for(int i=1;i<=6;i++)cout<<d[i]<<endl;
        if(k)cout<<"setwise coprime"<<endl;
        else cout<<"pairwise coprime"<<endl;
    }

    return 0;
}



