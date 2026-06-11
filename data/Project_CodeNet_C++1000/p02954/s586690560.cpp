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
  for(int i=0;i<S.size()-1;++i) {
    if(S[i]!=S[i+1]) {
      arr.push_back(i+1);
    }
  }
  int index;
  map<int, int> amap;
  for(int i=0;i<S.size();++i) {
    index = upper_bound(arr.begin(), arr.end(), i) - arr.begin();
    if(index%2==0) { // Lにとうちゃく
      if((arr[index]-i)%2==0) {
        amap[arr[index]]++;
      }
      else {
        amap[arr[index]-1]++;
      }
    }
    else {
      index--;
      if((i-arr[index])%2==0) {
        amap[arr[index]]++;
      }
      else {
        amap[arr[index]-1]++;
      }
    }
  }
  for(int i=0;i<S.size();++i) cout<<amap[i]<<" ";
  cout<<endl;
}

