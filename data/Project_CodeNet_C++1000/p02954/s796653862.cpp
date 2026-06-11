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
    if(nowr && S[i]=='L') {
      nowr = false;
      arr.push_back(i);
    }
    else if(!nowr && S[i]=='R') {
      nowr = true;
      arr.push_back(i);
    }
  }
  map<int, int> amap;
  int index;
  for(int i=0;i<S.size();++i) {
    if(S[i]=='R') {
      index = upper_bound(arr.begin(), arr.end(), i)-arr.begin();
      if((i-arr[index])%2==0) amap[arr[index]]++;
      else amap[arr[index]-1]++;
    }
    else {
      index = upper_bound(arr.begin(), arr.end(), i)-arr.begin()-1;
      if((i-arr[index])%2==0) amap[arr[index]]++;
      else amap[arr[index]-1]++;
    }
  }
  for(int i=0;i<S.size();++i) {
    cout<<amap[i]<<" ";
  }
  cout<<endl;
}

