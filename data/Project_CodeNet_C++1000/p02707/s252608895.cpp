#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265359

//素数判定
bool isPrime(int num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false;
  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2){
    if (num % i == 0) return false;
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n-1);
  rep(i,n-1) cin >> a[i];
  vector<int> ans(n);
  rep(i,n-1) ans[a[i]-1]+=1;
  rep(j,n) cout << ans[j] << endl;
}