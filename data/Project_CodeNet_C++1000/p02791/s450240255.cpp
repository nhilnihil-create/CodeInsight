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
#define pi 3.1415926535898
using namespace std;

int main()
{
    int m,n,ans=0;
    cin>>n;
    m=inf;
    int k;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(k<m)
        {
            m=k;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
