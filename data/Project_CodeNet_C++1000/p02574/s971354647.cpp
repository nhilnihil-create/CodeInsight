#include<bits/stdc++.h>
using namespace std;
#define l long int 
#define ll long long int 
vector<int>adj[1000001];
int vis[1000001];
int cnt=0;
int fact[1000001];
bool temp=false;
void f(int x)
{
    if(temp==true)
    return ;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            int a=i;
            int b=x/i;
            if(a==b)
            {
                a=i;
                b=1;
            }
            if(a!=1)
            {
                if(fact[a])
                {
                    temp=true;
                    return;
                }
                fact[a]++;
            }
            if(b!=1)
            {
                if(fact[b])
                {
                    temp=true;
                    return;
                }
                fact[b]++;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;  
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    int gcd=v[0];
    f(v[0]);
    for(int i=1;i<n;i++)
    {
        f(v[i]);
        gcd=__gcd(gcd,v[i]);
    }
    if(!temp)
    {
        cout<<"pairwise coprime"<<"\n";
    }
    else if (gcd==1)
    {
        cout<<"setwise coprime"<<"\n";
    }
    else
    {
        cout<<"not coprime"<<"\n";
    }
    
    
    return 0;
}