#include<cmath>
#include <iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<math.h>
#include<stack>
#include<algorithm>
#include<queue>
#include<bitset>
#include<sstream>
#define  ll long long int
const ll mod=20123;
using namespace std;
ll n,m;
string s;
ll a[200010];
map<ll,ll>p1,p2;
int main()
{
    ios::sync_with_stdio(false);
    ll i=0,j,flat1=0,flat2=0,x,k,y,z,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        p1[a[i]+i]++;
        p2[i-a[i]]++;
    }
    map<ll,ll>::iterator it;
    ll sum=0;
    for(it=p1.begin();it!=p1.end();it++)
    {
        sum+=(it->second)*p2[it->first];
    }
    cout<<sum;
      return 0;
}
