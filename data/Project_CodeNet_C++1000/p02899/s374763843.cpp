#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    long long n,i;
    cin>>n;
    pair<long long, long long> p[n];
    for(i=0;i<n;i++)
    {
        cin>>p[i].first;
        p[i].second=i+1;
    }
    sort(p,p+n);
    for(i=0;i<n;i++)
    {
        cout<<p[i].second<<" ";
    }
    return 0;
}