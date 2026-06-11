#include <bits/stdc++.h>
using namespace std;
typedef bool boool;
typedef long long ll;
#define vl vector<ll>
#define vb vector<boool>
#define vs vector<string>
#define vp vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define rep1(i, n) for (long long i=0; i<(long long)(n); i++)
#define rep2(i, s, e) for (long long i=(s); i<(long long)(e); i++)
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

int main(){
  int n;
  cin >> n;
  map<string, int> mp;
  rep(i, n){
    string str;
    cin >> str;
  	vector<char> vec(10);
  	rep(i, 10) vec[i] = str[i];
  	sort(all(vec));
  	rep(i, 10) str[i] = vec[i];
  	mp[str]++;
  }
  ll sum = 0;
  for(auto p : mp){
    ll num = p.second;
    sum += num*(num-1)/2;
  }
  cout << sum << endl;
  return 0; 
}
