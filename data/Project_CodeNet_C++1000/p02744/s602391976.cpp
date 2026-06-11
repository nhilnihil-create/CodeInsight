#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

void dfs(string s,ll res) {
  if(res==0) {
    cout << s << endl;
  }
  else {
    char lim='a';
    if(s!="") {
      for(ll i=0;i<s.size();i++) {
        lim=max(lim,s[i]);
      }
      lim++;
    }
    for(char i='a';i<=lim;i++) {
      dfs(s+i,res-1);
    }
  }
}

int main() {
  ll n;
  cin >> n;
  string s="";
  dfs(s,n);
}