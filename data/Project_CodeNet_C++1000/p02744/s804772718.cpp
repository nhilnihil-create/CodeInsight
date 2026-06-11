#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

vector<string> v;

int main(){
  ll n;cin >> n;
  queue<string> q;
  q.push("a");


  while( !q.empty() ){
    string s = q.front();q.pop();
    if( s.size() > n ) break;
    if( (ll)s.size() == n ){
      v.push_back(s);
    }
    string tmp = s;
    set<char> count_kind;
    rep(i,s.size()) count_kind.insert(s.at(i));
    rep(i,count_kind.size()+1){
      if( 'a'+i <= 'z' ){
        tmp.push_back('a'+i);
        q.push(tmp);
        tmp = s;
      }
    }
  }
  sort(v.begin(),v.end());
  for( auto p : v ){
    cout << p << '\n';
  }
  return 0;
}