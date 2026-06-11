#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265359

//階乗
ll factorial(ll num){ll sum = 1; for(ll i=1;i<=num;i++) sum*=i; return sum;}
//素数判定
bool isPrime(ll num){if(num<2){return false;}else if(num==2){return true;}else if(num%2==0){return false;} double sqrtNum=sqrt(num);for(int i=3;i<=sqrtNum;i+=2){if(num%i==0)return false;}return true;}

int main(){
  ll n;
  cin >> n;
  vector<int> a(n),b(n),c(n-1);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n-1) cin >> c[i];
  
  ll satisfaction = 0;
  rep(i,n) satisfaction += b[a[i]-1]; //単純満足度
  rep(i,n-1) if(a[i] +1 == a[i+1]) satisfaction += c[a[i]-1]; //掛け合わせ満足度
  
  cout << satisfaction << endl;
}