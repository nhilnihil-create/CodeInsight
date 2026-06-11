#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	
 ll n;
 cin>>n;
 ll a[n+1];
 ll k=1;
 std::vector<ll>v ;
 for(ll i=1;i<=n;i++)
 {
     cin>>a[i];
     if(a[i]==k)
     {
         v.push_back(k);
         k++;
     }
 }
 if(v.size()==0)
 {
     cout<<"-1\n";
 }
 else
 {
     cout<<n-v.size()<<"\n";
 }
}