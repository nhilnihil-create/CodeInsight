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
  vl vec(1001, 0);
  rep(i, n){
    int num;
    cin >> num;
    vec[num]++;
  }
  vl sum(1001, 0);
  sum[0] = 0;
  rep(i, 1, 1001){
    sum[i] = sum[i-1] + vec[i];
  }
  int ans = 0;
  rep(i, 1, 999){
    rep(j, i+1, 1000){
      ans += vec[i]*vec[j]*(sum[min(i+j-1, (ll)1000)]-sum[j]);
    }
  }
  rep(i, 1, 1001){
    ans += vec[i]*(vec[i]-1)*(vec[i]-2)/6;
    ans += vec[i]*(vec[i]-1)*sum[i-1]/2;
    ans += vec[i]*(vec[i]-1)*(sum[min(i+i-1, (ll)1000)]-sum[i])/2;
  }
  cout << ans << endl;
  return 0;
}
      
