#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  string S;
  cin>>S;
  string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(ll i=0;i<S.size();i++) {
 
for(ll j=0;j<26;j++) {
  if(S[i]==s[j]) {
if(j+N>25) {
cout<<s[j+N-26];
}
    else {
cout<<s[j+N];
    }
  }
}
  }
    
    cout<<endl;
  }
