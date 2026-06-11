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
  string str;
  cin >> str;
  ll n = str.length();
  ll k;
  cin >> k;
  bool allsame = true;
  char check = str[0];
  rep(i, 1, n){
    if(str[i] != check) allsame = false;
  }
  if(allsame){
    cout << n * k / 2 << endl;
    return 0;
  }
  if(str[0] != str[n-1]){
    ll sum = 0;
    char c = str[0];
    int cur = 1;
    rep(i, 1, n){
      if(str[i] == c) cur++;
      else{
        c = str[i];
        sum += cur/2;
        cur = 1;
      }
    }
    sum += cur/2;
    cout << sum * k << endl;
    return 0;
  }
  ll front = 1;
  char c = str[0];
  rep(i, 1, n){
    if(str[i] == c) front++;
    else{
      break;
    }
  }
  ll back = 1;
  c = str[n-1];
  for(int i=n-2; i>=0; i--){
    if(str[i] == c) back++;
    else{
      break;
    }
  }
  ll sum = 0;
  c = str[front];
  int cur = 1;
  for(int i=front+1; i<n-back; i++){
    if(str[i] == c) cur++;
    else{
      c = str[i];
      sum += cur/2;
      cur = 1;
    }
  }
  sum += cur/2;
  cout << front/2 + back/2 + (front+back)/2*(k-1) + sum*k << endl;
  return 0;
}
      