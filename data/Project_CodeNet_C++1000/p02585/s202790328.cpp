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
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  vector<int> c(n);
  rep(i, n){
    cin >> p[i];
    p[i]--;
  }
  rep(i, n){
    cin >> c[i];
  }
  ll gans=-1e18;
  rep(si, n){
    int x=si;
    ll tot=0;
    vector<int> s;
    while(1){
      x=p[x];
      tot+=c[x];
      s.push_back(c[x]);
      if(x==si){
        break;
      }
    }
    ll ans=-1e18;
    int l=s.size();
    ll sum=0;
    rep(i, l){
      if(i+1>k)break;
      sum+=s[i];
      ll ssum=sum;
      if(tot>0){
        ssum+=tot*((k-i-1)/l);
      }
      ans=max(ssum, ans);
    }

    gans=max(gans, ans);
  }
  cout << gans << endl;
  return 0;
}
