#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int k,x; cin>>k>>x;
  for(int i=x-k+1; i<x+k;i++){
    if(-1000000<=i&&i<=1000000){ cout<<i<<" ";}
  }
}

