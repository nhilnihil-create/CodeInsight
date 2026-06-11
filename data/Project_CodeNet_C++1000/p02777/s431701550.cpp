#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
map<string,ll> S;
  string s,t;
  cin>>s>>t;
  ll a,b;
  cin>>a>>b;
  S[s]=a;
  S[t]=b;
  string u;
  cin>>u;
  S[u]--;
  cout<<S[s]<<" "<<S[t]<<endl;
}