#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
int main(void){
    // Your code here!
 ll k,m,n,s,x;
 s=0;
 map<ll,ll> mp;
 cin >> n >> m;
 while(n--)
 {
  cin >> x;
  mp[x]++;
 }
 while(m--)
 {
  auto it=mp.end();
  it--;
  k=(it->ff)/2;
  mp[it->ff]--;
  if(mp[it->ff]==0)
  mp.erase(it->ff);
  mp[k]++;
 }
 for(auto it:mp)
 s+=(it.ff*it.ss);
 cout << s;
 return 0;
}