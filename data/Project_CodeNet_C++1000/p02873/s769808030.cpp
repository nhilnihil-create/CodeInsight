#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S;
  cin>>S;
  bool up = false;
  if(S[0]=='<') up = true;
  vector<ll> arr;
  arr.push_back(0);
  for(ll i=1;i<S.size();++i) {
    if(up && S[i]=='>') {
      up = false;
      arr.push_back(i);
    }
    else if(!up && S[i]=='<') {
      up = true;
      arr.push_back(i);
    }
  }
  arr.push_back(S.size());
  ll ans = 0;
  ll num;
  if(S[0]=='<') {
    for(ll i=1;i<arr.size();++i) {
      if(i%2==0) { // tani
        num = max(arr[i]-arr[i-1], arr[i-1]-arr[i-2]);
        if(num==arr[i]-arr[i-1]) ans += num*(num+1)/2;
        else ans += (arr[i]-arr[i-1])*(arr[i]-arr[i-1]+1)/2 - (arr[i]-arr[i-1])+num;
      }
      else { // yama
        if(i==arr.size()-1) {
          ans += (arr[i]-arr[i-1])*(arr[i]-arr[i-1]+1)/2;
        }
        else {
          num = max(arr[i+1]-arr[i], arr[i]-arr[i-1]);
          if(num==arr[i]-arr[i-1]) ans += num*(num+1)/2-num;
          else ans += (arr[i]-arr[i-1])*(arr[i]-arr[i-1]+1)/2-(arr[i]-arr[i-1]);
        }
      }
    }
  }
  else {
    for(ll i=1;i<arr.size();++i) {
      if(i%2!=0) { // tani
        num = max(arr[i]-arr[i-1], arr[i-1]-arr[i-2]);
        if(num==arr[i]-arr[i-1]) ans += num*(num+1)/2;
        else ans += (arr[i]-arr[i-1])*(arr[i]-arr[i-1]+1)/2 - (arr[i]-arr[i-1])+num;
      }
      else { // yama
        if(i==arr.size()-1) {
          ans += (arr[i]-arr[i-1])*(arr[i]-arr[i-1]+1)/2;
        }
        else {
          num = max(arr[i+1]-arr[i], arr[i]-arr[i-1]);
          if(num==arr[i]-arr[i-1]) ans += num*(num+1)/2-num;
          else ans += (arr[i]-arr[i-1])*(arr[i]-arr[i-1]+1)/2-(arr[i]-arr[i-1]);
        }
      }
    }
  }
  cout<<ans<<endl;
}
