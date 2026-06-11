#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main() { 
   int h1,m1,h2,m2,k;
   cin>>h1>>m1>>h2>>m2>>k;
   m1 = h1*60 + m1;
   m2 = h2*60 + m2;
   int ans = m2 - m1 - k;
   cout<<ans<<endl;
}  