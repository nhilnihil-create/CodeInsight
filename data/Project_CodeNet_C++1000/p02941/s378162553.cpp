//
//  main.cpp
//  MST2ND
//
//  Created by Dong Truong on 7/13/19.
//  Copyright © 2019 Dong Truong. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
#define long long long

const long maxn = 1e6+2 , cm=1e9+7 , ba=31;
struct elem
{
    long id,gt;
};
struct cmp
{
    bool operator () (elem a,elem b)
    {
        return a.gt<b.gt;
    }
};

long n,a[maxn],b[maxn];
priority_queue<elem,vector <elem>,cmp> pq;

void nhap()
{
    cin>>n;
    cin>>a[1];
    pq.push({1,a[1]});
    for (int i=2;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        cin>>b[i];
        pq.push({i,b[i]});
    }
}
void sol()
{
    long ans=0;
    while (!pq.empty())
    {
        long o=pq.top().id,u=pq.top().gt;
        pq.pop();
        long kc=u-a[o],l=o-1,z=b[o];
        if (l==0) l=n;
        ans+=kc / (b[l]+b[o%n+1]);
        b[o]=a[o]+kc % (b[l]+b[o%n+1]);
        if (z!=b[o])
            pq.push({o,b[o]});
    }
    bool kt=true;
    for (int i=1;i<=n;++i)
        if (a[i]!=b[i]) kt=false;
    if (kt==true) cout<<ans;
    else cout<<-1;
}
int main(int argc, const char * argv[]) {
   // freopen("a.inp","r",stdin);
    nhap();
    sol();
    return 0;
}
