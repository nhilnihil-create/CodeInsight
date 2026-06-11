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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S;
  cin>>S;
  vector<ll> arr;
  ll num = 1;
  bool up;
  if(S[0]=='<') up = true;
  else up = false;

  for(int i=1;i<S.size();++i) {
    if(S[i]=='<') {
      if(up) {
        num++;
      }
      else {
        arr.push_back(num);
        num = 1;
        up = true;
      }
    }
    else {
      if(up) {
        arr.push_back(num);
        num = 1;
        up = false;
      }
      else {
        num++;
      }
    }
  }
  arr.push_back(num);
  ll ans = 0;
  for(int i=0;i<arr.size();++i) ans += arr[i]*(arr[i]-1)/2;
  if(S[0]=='<') {
    for(int i=0;i<arr.size();++i) {
      if(i%2==0) {
        if(i==arr.size()-1) {
          ans += arr[i];
        }
        else {
          ans += max(arr[i], arr[i+1]);
        }
      }
    }
  }
  else {
    ans += arr[0];
    for(int i=0;i<arr.size();++i) {
      if(i%2==1) {
        if(i==arr.size()-1) ans += arr[i];
        else ans += max(arr[i], arr[i+1]);
      }
    }
  }
  cout<<ans<<endl;
}
