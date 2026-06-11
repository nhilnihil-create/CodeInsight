#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 string S="abcdefghijklmnopqrstuvwxyz";
  char a;
  cin>>a;
  for(ll i=0;i<26;i++) {
    
if(a==S[i]) {
cout<<S[i+1]<<endl;
}
  }
}
