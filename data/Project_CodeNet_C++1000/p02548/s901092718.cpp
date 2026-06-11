#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll n;
	cin>>n;
  ll cnt=0;
  for(ll i=1;i<n;i++)
  {
    cnt+=(n-1)/i;
  }
  cout<<cnt<<"\n";
  return 0;
}