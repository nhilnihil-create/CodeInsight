#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  ll c,l;
  vector<ll> s;
  vector<ll> ord(n+1,-1);
  ll v=0;
  while(ord[v]==-1){
    ord[v]=s.size();
    s.push_back(v);
    v=a.at(v)-1;
  }
  l=ord[v];
  c=s.size()-ord[v];
  if(k<l){
    cout << s.at(k)+1;
  }else{
    k-=l;
    k%=c;
    cout << s.at(l+k)+1;
  }
}