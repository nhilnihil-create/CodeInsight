#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>
#include<math.h>
#define ll long long
#define INF 0x3f3f3f3f
#define inf  0x3ffffffffffff
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int  maxn=8000009;
const double pi = acos(-1.0);
const int N=40010;
using namespace std;
const ll mod=1e9+7;
map<ll,ll>mp;
int a[200000];
int main()
{
   int n;
   ll sum=0;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
      mp[i+a[i]]++;
   }
   for(int i=1;i<=n;i++)
    sum+=mp[i-a[i]];
   cout<<sum<<endl;
    return 0;
}