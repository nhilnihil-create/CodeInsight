#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main()
{
    long long int n,k;
    cin>>n>>k;
    vector<long long int> v(n);
    rep(i,n) cin>>v[i];
    sort(v.begin(),v.end());
    long long int s = 0;
    rep(i,n-k) s=s+v[i];
    cout<<s<<endl;
   
   return 0;
}