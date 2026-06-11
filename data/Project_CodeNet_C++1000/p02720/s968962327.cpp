#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
using namespace std;
queue<ll> q;
int n;
int main()
{

    cin>>n;
    for(int i=1;i<=9;i++)
    {
        q.push(i);
    }
    for(int i=1;i<=n;i++)
    {

        ll pre=q.front();
        q.pop();
        if(i==n)
        {
            cout<<pre<<endl;
        }
        ll r=pre%10;
        pre=pre*10+r;
        if(r>0)
            q.push(pre-1);
        q.push(pre);
        if(r<9)
        {
            q.push(pre+1);
        }
    }

    return 0;
}
