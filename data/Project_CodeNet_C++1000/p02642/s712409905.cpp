#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN]={0};
map<int,int>mm;
int vis[MAXN]={0};
int solve(int n,int maxnum){
    if(vis[n])
        return 0;
    for(int i=n;i<=maxnum;i+=n)
        vis[i]=1;
    if(mm[n]>1)
        return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mm[a[i]]++;
    }
    sort(a,a+n);
    int ans = 0;
    for(int i=0;i<n;i++)
        ans+=solve(a[i],a[n-1]);
    cout <<ans << endl;
    return 0;
}
