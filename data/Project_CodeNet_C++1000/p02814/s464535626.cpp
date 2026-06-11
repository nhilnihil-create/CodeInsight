#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return b ? gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

int f(int &a){
  int cnt=0;
  while(a%2 == 0){
    a /= 2;
    ++cnt;
  }
  return cnt;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> vec(n);
  for(int i=0; i<n; ++i){
    cin >> vec.at(i);
    if(vec.at(i)%2 != 0){
      cout << 0 << endl;
      return 0;
    }
    vec.at(i) /=2;
  }
  int t=f(vec.at(0));
  for(int i=1; i<n; ++i){
    if(t != f(vec.at(i))){
      cout << 0 << endl;
      return 0;
    }
  }
  for(int i=0; i<t; ++i){
    m /= 2;
  }
  ll l=1;
  for(int i=0; i<n; ++i){
    l = lcm(l, vec.at(i));
    if(l > m){
      cout << 0 << endl;
      return 0;
    }
  }
  m /= l;
  int ans= (m+1)/2;
  cout << ans << endl;
}