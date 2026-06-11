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
  map<int, int> mp;
  rep(i, n){
    cin >> a[i];
    mp[a[i]]++;
  }
  ll sum=0;
  for(auto p: mp){
    ll mm=p.second;
    sum+=mm*(mm-1)/2;
  }
  rep(i, n){
    ll ans=sum;
    int m=mp[a[i]];
    ans-=m*(m-1)/2;
    m--;
    ans+=m*(m-1)/2;
    cout << ans << endl;
  }
  return 0;
}
