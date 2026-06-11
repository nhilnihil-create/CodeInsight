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
  vector<int> arr;
  bool nowr = true;
  arr.push_back(0);
  for(int i=1;i<S.size();++i) {
    if(nowr) {
      if(S[i]=='L') {
        arr.push_back(i);
        nowr = false;
      }
    }
    else {
      if(S[i]=='R') {
        arr.push_back(i);
        nowr = true;
      }
    }
  }
  int index;
  int ans[S.size()];
  for(int i=0;i<S.size();++i) {
    index = upper_bound(arr.begin(), arr.end(), i)-arr.begin();
    if(index%2==0) { // R
      index = arr[index-1];
      if((i-index)%2==0) {
        ans[i] = index;
      }
      else {
        ans[i] = index - 1;
      }
    }
    else {
      index = arr[index];
      if((i-index)%2==0) {
        ans[i] = index;
      }
      else {
        ans[i] = index-1;
      }
    }
  }
  map<int, int> amap;
  for(int i=0;i<S.size();++i) {
    amap[ans[i]]++;
  }
  for(int i=0;i<S.size();++i) cout<<amap[i]<<" ";
  cout<<endl;
}

