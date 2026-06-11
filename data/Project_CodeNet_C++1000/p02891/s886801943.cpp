#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<char>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pll = pair<ll, ll>;

int main() {
  string s; ll k;
  cin>>s>>k;
  ll n=0;
  rep(i,s.size()-1){
    if(s[i]==s[i+1]){n++; i++;}
  }
  ll ans=n*k;
  if(count(s.begin(),s.end(),s[0])==s.size()){
    if(s.size()%2==1){ans=s.size()*k/2;}
    
  }
  else if(s[0]==s[s.size()-1]){
    int i=1;ll m=2;
    while(s[i]==s[0]){m++; i++;}
    i=s.size()-2;
    while(s[i]==s[0]){m++; i--;}
   if(m%2==0){ans+=k-1;}
  }
  cout<<ans;
}