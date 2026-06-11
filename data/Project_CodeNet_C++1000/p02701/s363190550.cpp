#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  sort(s.begin(),s.end());
  s.erase(unique(s.begin(),s.end()),s.end());
  cout << s.size() << endl;
}