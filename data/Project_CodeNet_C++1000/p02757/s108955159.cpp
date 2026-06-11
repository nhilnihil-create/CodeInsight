#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
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
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  ll ans=0;
  if(p==2 || p==5){
    rep(i, n){
      if((int)(s[i]-'0')%p==0){
        ans+=i+1;
      }
    }
    cout << ans << endl;
  } else {
    int ten=1;
    vector<int> d(n+1);
    map<int, int> mp;
    mp[0]++;
    for(int i=n-1; i>=0; i--){
      int a=(int)(s[i]-'0')*ten%p;
      d[i]=(d[i+1]+a)%p;
      mp[d[i]]++;
      ten*=10;
      ten%=p;
    }
    for(auto p:mp){
      ans+=(ll)p.second*(p.second-1)/2;
    }
    cout << ans << endl;
  }
  return 0;
}
