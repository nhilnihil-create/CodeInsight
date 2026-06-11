#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

ll judge(set<ll> &x,set<ll>&y,vector<vector<char>> &z,ll h,ll w) {
  ll count=0;
  for(ll i=0;i<h;i++) {
for(ll j=0;j<w;j++) {
if(x.count(i) ) {
break;
}
  if(y.count(j) ){
    continue;
  }
  if(z[i][j]=='#') {
    count++;
  }
}
  }
  
  return count;
}

 
int main() {
  
ll H,W,K;
  cin>>H>>W>>K;
  ll ans=0;
  
  vector<vector<char>> vec(H,vector<char>(W));
  for(ll i=0;i<H;i++) {
for(ll j=0;j<W;j++) {
cin>>vec[i][j];
}
  }
  
  ll size=H+W;
  for(ll tmp=0;tmp<(1<<size);tmp++) {
bitset<12> s(tmp);
    set<ll> HS;
    set<ll> WS;
    for(ll i=0;i<H;i++) {
if(s.test(i)) {
HS.insert(i);
}
    }
    for(ll i=0;i<W;i++) {
if(s.test(i+H)) {
  WS.insert(i);
}
    }

    if(judge(HS,WS,vec,H,W)==K) {
      ans++;
    }
  }
  
  cout<<ans<<endl;
}


    