#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = (a); i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const ll bd = pow(10,18);

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  int flg = 0;
  rep(i,0,n){
    cin >> a[i];
    if(a[i]==0) flg = 1;
  }
  if(flg){
    cout << 0 << endl;
    return 0;
  }
  ll prod = 1;
  rep(i,0,n){
    if(prod>bd/a[i]){
      cout << -1 << endl;
      return 0;
    }
    prod *= a[i];
    if(prod>bd){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << prod << endl;
  return 0;
}