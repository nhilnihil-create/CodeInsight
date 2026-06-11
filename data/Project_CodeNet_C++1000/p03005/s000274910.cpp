#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define ll long long
//map<key,value>

int main(){
  int n,k;
  cin >> n >> k;
  if(k>1)std::cout << n-k << '\n';
  else cout << "0";
  return 0;
}