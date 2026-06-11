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

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n){
    cin >>a[i];
  }
  map<int, int> mp;
  ll ans=0;
  repo(i, n-1){
    mp[i-1+a[i-1]]++;
    int nma=i-a[i];
    ans+=mp[nma];
  }
  cout << ans << endl;
  return 0;
}
