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
  ll n, k;
  cin >> n >> k;
  vector<ll> next(n);
  rep(i, n){
    ll num;
    cin >> num; num--;
    next[i] = num;
  }
  vector<ll> point(n);
  rep(i, n) cin >> point[i];
  ll biggest = -1000000000000000001;
  rep(i, n){
    vector<ll> tmp;
    ll c = i;
    ll sbiggest = -1000000000000000001;
    ll sum = 0;
    while(next[c] != i){
      c = next[c];
      sum += point[c];
      sbiggest = max(sbiggest, sum);
      tmp.push_back(c);
    }
    sum += point[i];
    sbiggest = max(sbiggest, sum);
    tmp.push_back(i);
    if(sum <= 0){
      if(k <= (ll)tmp.size()){
        ll b = -1000000000000000001;
        ll csum = 0;
        rep(j, k){
          csum += point[tmp[j]];
          b = max(b, csum);
        }
        biggest = max(biggest, b);
      }else{
        ll b = -1000000000000000001;
        ll csum = 0;
        rep(j, (ll)tmp.size()){
          csum += point[tmp[j]];
          b = max(b, csum);
        }
        biggest = max(biggest, b);
      }
    }else{
      if(k <= (ll)tmp.size()){
        ll b = -1000000000000000001;
        ll csum = 0;
        rep(j, k){
          csum += point[tmp[j]];
          b = max(b, csum);
        }
        biggest = max(biggest, b);
      }else{
        ll b1 = 0;
        ll csum1 = 0;
        rep(j, k%tmp.size()){
          csum1 += point[tmp[j]];
          b1 = max(b1, csum1);
        }
        ll b2 = 0;
        ll csum2 = 0;
        rep(j, k%tmp.size(), tmp.size()){
          csum2 += point[tmp[j]];
          b2 = max(b2, csum2);
        }
        biggest = max(biggest, (ll)(b1+sum*(k/tmp.size())));
        biggest = max(biggest, (ll)(b2+sum*(k/tmp.size()-1)));
      }
    }
  }
  cout << biggest << endl;
  return 0;
}
