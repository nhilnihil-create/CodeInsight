#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main() {
  int a; cin>>a;
  if(a<100){cout<<0;}
  else if(a/100*5 >= a%100){cout<<1;}
  else{cout<<0;}
}
      