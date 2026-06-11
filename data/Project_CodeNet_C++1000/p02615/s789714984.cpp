#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
   ll n,i,l,s=0; vector<ll>a; cin>>n;
   for(i=0;i<n;i++) {cin>>l; a.pb(l); }
   sort(a.begin(),a.end(),greater<int>());
   for(i=0;i<n-1;i++)
   { s+=a[(i+1)/2];}
   cout<<s;
	return 0;
}