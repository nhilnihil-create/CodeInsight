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
  ll n,m;
  cin >> n >> m;
  
  vector<bool> ok(n);
  vector<int> pena(n);
  rep(i,n) ok[i] = false;
  rep(i,n) pena[i] = 0;
  
  int penalty = 0;
  int answer = 0;
  rep(i,m){
    int p; string s;
    cin >> p >> s;
    if(!ok[p-1] && s == "WA"){
      pena[p-1]++;
    }
    if(!ok[p-1] && s == "AC"){
      penalty += pena[p-1]; //ACが出ない限りペナルティ数は数えても意味無し
      answer++;
      ok[p-1] = true;
    }
  }
  
  cout << answer << " " << penalty << endl;
}