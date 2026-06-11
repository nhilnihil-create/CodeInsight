#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  string s;
  cin>>s;
  bool ans=0;
  if(s=="hi") ans=1; 
  if(s=="hihi") ans=1; 
  if(s=="hihihi") ans=1; 
  if(s=="hihihihi") ans=1; 
  if(s=="hihihihihi") ans=1; 
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}