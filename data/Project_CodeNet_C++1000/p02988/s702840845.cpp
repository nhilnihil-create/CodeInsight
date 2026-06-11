#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define All(a) a.begin(),a.end()
#define INF 1000000007
const int MOD = 1000000007;
//accumulate(vec.begin(), vec.end(), 0)
//std::sort(v.begin(), v.end(), std::greater<Type>());

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
  int n;
  int cnt=0;
  cin >> n;
  vector<int>p(n);
  for(int i=0;i<n;i++) cin >> p[i];
  for(int i=1;i<n-1;i++){
    if(p[i-1] < p[i] && p[i]<p[i+1]) cnt++;
    else if(p[i-1] > p[i] && p[i]>p[i+1]) cnt++;
  }
  cout<< cnt <<endl;
}
