#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n,l; cin>>n>>l;
  int a=n*(2*l+n-1)/2;
  if(l>=0)a-=l;
  else if(l<1-n)a-=l+n-1;
  cout<<a;
}