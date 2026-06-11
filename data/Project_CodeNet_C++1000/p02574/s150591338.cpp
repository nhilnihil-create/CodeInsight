#include <iostream>
#include <bits/stdc++.h>
#include <set>
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define ll long long
#define ull unsigned long long
#define MAXN 1000000007
#define INF 1e12
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> trip;
typedef pair<ll int,ll int> pli;
typedef vector<int> vi;
typedef vector<ll int> vli;
typedef vector<vi> vvi;
string getString(char x)
{
    string s(1, x);

    return s;
}
int highestPowerof2(ll int n)
{if(n==0)
    return 0;
   int p = (int)log2(n);
   //cout<<p<<"highest"<<endl;
   return p;
}

int main()
{ios::sync_with_stdio(0);
	cin.tie(0);
    int test=1;
    //int cas=
    //cin>>test;
    vector<int>fact(1e6+1,0);
    for(int i=0;i<=1e6;i++)
        fact[i]=i;
    for(int i=2;i<=1e6;i++)
    {
        if(fact[i]==i)
        {
            for(int j=1;j*i<=1e6;j++)
                fact[j*i]=i;
        }
    }
    while(test--)
    {
       int n;
        cin>>n;
        vi vec(n);
        vi f(1e6+1,0);
        for(int i=0;i<n;i++)
        {cin>>vec[i];
         int k=vec[i];
         map<int,int>ma;
         //cout<<vec[i]<<" ";
         while(k>1)
         {
             int p=fact[k];
             //cout<<p<<" ";
             if(ma[p]==0)
             {ma[p]=1;f[p]++;}
             k/=p;
         }
         //cout<<endl;

        }
        int check=1;
        for(int i=0;i<f.size();i++)
        {
            if(f[i]>1)
                {check=0;}
        }
        if(check)
        {
            cout<<"pairwise coprime"<<endl;continue;
        }
        check=1;
        for(int i=0;i<f.size();i++)
        {
            if(f[i]>=n)
                {check=0;}
        }
        if(check)
        {
            cout<<"setwise coprime"<<endl;continue;
        }
        cout<<"not coprime"<<endl;

    }

}
