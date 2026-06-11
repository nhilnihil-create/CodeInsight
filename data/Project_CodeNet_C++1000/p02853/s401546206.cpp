#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define All(a) a.begin(),a.end()
#define INF 1000000007
const int MOD = 1000000007;
//accumulate(vec.begin(), vec.end(), 0)

int gcd(int x,int y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}

bool isPrime(int n){
  if(n < 2) return false;
  else if(n == 2) return true;
  else if(n%2==0) return false;

  for(int i=3;i<=sqrt(n);i++){
    if(n%i==0) return false;
  }
  return true;
}

int main(){
  int x,y;
  cin >> x >> y;
  int ans = 0;
  if(x==1) ans += 300000;
  else if(x==2) ans += 200000;
  else if(x==3) ans += 100000;

  if(y==1) ans += 300000;
  else if(y==2) ans += 200000;
  else if(y==3) ans += 100000;

  if(x==1 && y==1) ans += 400000;
  cout<< ans <<endl;
}
