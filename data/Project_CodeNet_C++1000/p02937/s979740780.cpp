#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod=1000000007;
const ll inf=1e18;
int main(){
  string s,t;
  cin >> s >> t;
  ll k=0;
  map<char,vector<ll>> v;
  for(int i=0;i<s.size();i++){
    v[s[i]].push_back(i);      
  }
  for(int i=0;i<t.size();i++){
    if(v[t[i]].size())k++;
  }
 
  ll l;
 
  if(k!=t.size())cout << -1 << endl;
  else{
    k=-1;
    ll p=0;
    for(int i=0;i<t.size();i++){
      l=lower_bound(v[t[i]].begin(),v[t[i]].end(),k+1)-v[t[i]].begin();
      if(l==v[t[i]].end()-v[t[i]].begin()){
        p++;
        k=v[t[i]][0];
      }
      else{
        k=v[t[i]][l];
      }
    }
 
    cout << p*s.size()+k+1 << endl;
 
  }
 
}