#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  string s;
  string t;
  cin >> s;
  cin >> t;
  vector<ll>s_char[26];
  for(int i=0; i<s.size(); i++){
    int S = s[i]-'a';
    int I = i;
    s_char[S].push_back(I);
  }
  
  ll MAX=0;
  for(int i=0; i<t.size(); i++){
    ll T = t[i]-'a';
    ll ss = s_char[T].size();
    ll n = MAX/s.size()+1;
    if(!ss){
      cout << -1 << endl;
      return 0;
    }
    ll x=0,j=0;
    if(s.size()*n-s.size()+s_char[T][ss-1]<MAX)n++;
    x=MAX-s.size()*n+s.size()-1;
    while(s_char[T][j]<=x){
      j++;
    }
    MAX=s.size()*n-s.size()+s_char[T][j]+1;
    //cout << x << endl;
  }
  cout << MAX << endl;
}
  
  
  
  
