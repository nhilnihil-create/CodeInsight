#include<iostream>
//#include <cmath>
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
#define FOR(i,a,n) for(ll i=(a);i<(n);++i)
#define ROF(i,a,n) for(int i=(a);i>(n);--i)

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 //   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n;cin>>n; cout<<ceil(float(n)/1000)*1000-n;
    return 0;
}