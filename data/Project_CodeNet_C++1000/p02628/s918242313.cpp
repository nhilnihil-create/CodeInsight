#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iterator>
#include<deque>
#include<cstdio>

#define lp(i,a,n) for(int i=a;i<n;++i)
#define rep(i,a,n) for(ll i=a;i<=n;++i)
#define all(v) v.begin(),v.end()
#define clr(n,a) memset(n,a,sizeof(n))
#define vi vector <int>
#define sc set <char>
#define si set<int>
#define pb push_back
#define vb vector <bool>
#define pi(n) printf("%d\n",n)
#define ln "\n"
#define mahmoud_abdelsamie ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


int main()
{
    mahmoud_abdelsamie
    int n,k;
    cin>>n>>k;
    int a[n]={};
    lp(i,0,n) cin>>a[i];
    sort(a,a+n);
    ll sum=0;
    lp(i,0,k) sum+=a[i];
    cout<<sum<<ln;
    return 0;
}
