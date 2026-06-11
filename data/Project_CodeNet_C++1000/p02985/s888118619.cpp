#include <iostream>
#include <bits/stdc++.h>

#define mod 1000000007
using namespace std;
int n,k;
vector<int> rad[100005];

long long gv(int now,int from,int l1,int l2)
{
    long long ret =1;
    int nm = 0;
    long long tm = 1;

    for(int i=0;i<rad[now].size();++i)
    {
        if(rad[now][i]==from) continue;
        ret *= gv(rad[now][i],now,1,l1+rad[now].size()-1-(from==-1?0:1));
        ret %= mod;
        tm *= k-l1-1-nm;
        tm %= mod;
        ++nm;
    }
    return ret*tm%mod;
}

int main()
{
    scanf("%d%d",&n,&k);
    int l,r;
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&l,&r);
        rad[l].push_back(r);
        rad[r].push_back(l);
    }

    printf("%lld\n",gv(1,-1,0,0)*k%mod,0,0);
    return 0;
}
