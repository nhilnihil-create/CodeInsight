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
int a[200020];
int b[200020];
char c[200020];
int n,k,c1;
int main()
{
    int p=0,q=0;
    int temp=99999999;
    cin>>n>>k>>c1;
    cin>>c;
    for(int i=0; i<n; i++)
    {
        if(p==k)
        {
            break;
        }
        if(c[i]=='o'&&temp>=c1)
        {
            a[p++]=i;
            temp=0;
        }
        else
        {
            temp++;
        }

    }
    temp=99999999;
    q=k-1;
    for(int i=n-1; i>=0; i--)
    {
        if(q<0)
        {
            break;
        }
        if(c[i]=='o'&&temp>=c1)
        {
            b[q--]=i;
            temp=0;
        }
        else
        {
            temp++;
        }
    }
    for(int i=0;i<k;i++)
    {
        if(a[i]==b[i])
        {
            cout<<a[i]+1<<endl;
        }
    }
    return 0;
}
