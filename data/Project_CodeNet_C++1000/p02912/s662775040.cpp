#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
ll n,m;
ll ans;
priority_queue<int>q;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ans+=x;
        q.push(x);
    }
    for(int i=0;i<m;i++)
    {
        int x=q.top();
        q.pop();
        ans=ans-x+x/2;
        q.push(x/2);
    }
    cout<<ans<<endl;
    return 0;
}
