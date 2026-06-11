#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  set<string> S;
  for(ll i=0;i<N;i++) {
string s;
    cin>>s;
    S.insert(s);
  }
  cout<<S.size()<<endl;
}
  