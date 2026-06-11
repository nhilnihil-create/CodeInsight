#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

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
  ll n,k,q;
  cin >> n >> k >> q;
  
  vector<int> player(n);
  rep(i,n) player[i] = k-q;
  
  rep(i,q){
    int answer = 0; cin >> answer;
    player[answer-1]++;
  }
  
  rep(i,n){
    if(player[i]>0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}