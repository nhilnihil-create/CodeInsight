#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
  string s;
  cin >> s;
  map<int, int> mp;
  int n=s.size();
  vector<int> T(n);
  mp[0]++;
  for(int i=n-1; i>=0; i--){
    int a=s[i]-'0';
    if(i==n-1){
      T[i]=a;
      mp[T[i]]++;
    } else {
      T[i]=T[i+1]+a*modpow(10, n-1-i, 2019);
      T[i]%=2019;
      mp[T[i]]++;
    }

  }
  ll ans=0;
  for(auto p:mp){
    int m=p.second;
    ans+=m*(m-1)/2;
  }
  cout << ans << endl;
  return 0;
}
