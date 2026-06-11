#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

long long int n, d[200000], c[200000];

int main(){
  cin >> n;
  rep(i, n) d[i] = 0;
  long long int mx = 0;
  bool flag = false;
  rep(i, n){
    long long int tmp;
    cin >> tmp;
    d[tmp]++;
    mx = max(mx, tmp + 1);
    if(i == 0 && tmp == 0){
      flag = true;
    }
  }
  long long int sum;
  if(flag && d[0] == 1){
    sum = 1;
  }else{
    sum = 0;
  }
  rep(i, mx) cerr << d[i] <<" "; cerr << endl;
  for(int i = 1; i < mx; i++){
    long long int a = d[i - 1], b = d[i];
    long long int tmp = 1;
    rep(j, b){
      tmp *= a;
      tmp %= 998244353;
    }
    cerr << tmp << endl;
    sum *= tmp;
    sum %= 998244353;
  }
  cout << sum << endl;
  return 0;
}
