#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
string s;
vector<int> v;

ll calc(ll x, ll y) {
  if(x < y) swap(x,y);
  return x*(x+1)/2 + y*(y-1)/2;
}

int main() {
  cin>>s;
  int N = s.size();
  int cnt = 0;
  
  if(s[0] != '<') {
    v.pb(0);
  }
  
  for(int i=0;i<N;++i) {
    ++cnt;
    if(i == N-1 || s[i] != s[i+1]) {
      v.pb(cnt);
      cnt = 0;
    }
  }
  if(s[N-1] != '>') {
    v.pb(0);
  }
  ll sum = 0;

  for(int i=0;i<v.size();i+=2) {
    sum += calc(v[i], v[i+1]);
  }

  cout<<sum<<"\n";
  return 0;
}