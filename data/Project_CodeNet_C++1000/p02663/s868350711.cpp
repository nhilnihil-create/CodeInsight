#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int lli;
int main()
{
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
  int h1,m1,h2,m2,k,sum;
  cin>>h1>>m1>>h2>>m2>>k;
  sum=(h2-h1)*60 + (m2-m1);
  cout<<max(0,sum-k);
}