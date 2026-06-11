#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll a,b; cin>>a>>b;
  if((a+b)%2==0)cout<<(a+b)/2;
  else{cout<<"IMPOSSIBLE";}
}

