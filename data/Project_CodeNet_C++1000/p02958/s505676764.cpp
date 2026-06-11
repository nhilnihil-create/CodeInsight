#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include<cstdlib>


#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define vin(v) for (ll i = 0; i < v.size(); ++i) cin >> v[i];
#define vout(v, c) for (int i = 0; i < v.size(); ++i) cout << v[i] << c;

typedef long long ll;
using namespace std;

int main()
{
     ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
     int n,i,k,l,c=0,d,p,nl,np;
    int a[51],b;
   cin>>n;
   vector<int> v(n);

   REP(i,n)
   {
    cin>>v[i];

   }
   REP(i,n)
   {
       if(v[i]!=i+1)c++;

   }

   if(c==2 || c==0)cout<<"YES";
   else cout<<"NO";





}