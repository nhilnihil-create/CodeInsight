#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int a,b,c; cin>>a>>b>>c;
  if(c<a-b){cout<<0;}
  else{cout<<c-a+b;}
}
      

