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
#define inf 0x3f3f3f3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=1e6+10;
const int mod=1e9+7;
int a[N],b[N];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i]=x+y;
        b[i]=x-y;
    }
    sort(a,a+n);
    sort(b,b+n);
    cout<<max(a[n-1]-a[0],b[n-1]-b[0])<<endl;
    return 0;

}
