#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;
  string S;
  map<string, ll> cnt;
  rep(i, N){
    cin >> S;

    cnt[S]++;
  }

  ll num = -1;
  
  for(auto it = cnt.begin(); it != cnt.end(); it++)
    num = max(num, it->second);

  set<string> strs;

  for(auto it = cnt.begin(); it != cnt.end(); it++){
    if(it->second == num)
      strs.insert(it->first);
  }

  for(auto it = strs.begin(); it != strs.end(); it++)
    cout << (*it) << "\n";
  
  return 0;
}
