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
  string s, t;
  cin >> s >> t;
  int ssz=s.size(), tsz=t.size();
  vector<int> sindex[26];
  rep(i, ssz){
    sindex[s[i]-'a'].push_back(i);
  }
  int num=0;
  ll ans=0;
  int ti=0;
  while(ti<tsz){
    auto it=lower_bound(sindex[t[ti]-'a'].begin(), sindex[t[ti]-'a'].end(), num);
    if(it==sindex[t[ti]-'a'].end() &&num!=0){
      ans+=ssz-num;
      num=0;
    } else if(it==sindex[t[ti]-'a'].end() &&num==0){
      cout << "-1" << endl;
      return 0;
    } else if(it!=sindex[t[ti]-'a'].end()){
      int tmp=num;
      ans+=*it+1-tmp;
      num+=*it+1-tmp;
      ti++;
    }

  }
  cout << ans << endl;
  return 0;
}
