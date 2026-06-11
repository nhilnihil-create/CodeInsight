#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using T = tuple<string,int,int>;

int main(){
  int n,k,s;
  cin >> n >> k >> s;
  int a = s+1;
  if(a > 1000000000){
    a = 1;
  }
  rep(i,k) cout << s << " ";
  for(int i = k; i < n; i++) cout << a << " ";
  cout << endl;
  return 0;
}