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
#define inf 0x3f3f3f3f3f3f3f3f
#define pi 3.1415926535898

#define N 200010
using namespace std;

ll ans;
ll a[N],s[N];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans+=s[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans-s[a[i]]+1<<endl;
    }
    return 0;
}
