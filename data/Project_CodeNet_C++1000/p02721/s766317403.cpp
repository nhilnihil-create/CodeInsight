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
  int N, K, C;
  cin>>N>>K>>C;
  string S;
  cin>>S;
  vector<int> arr1, arr2;
  map<int, int> amap;
  for(int i=0;i<S.size();++i) {
    if(S[i]=='o') {
      arr1.push_back(i);
      i += C;
    }
  }

  for(int i=S.size()-1;i>=0;--i) {
    if(S[i]=='o') {
      arr2.push_back(i);
      i -= C;
    }
  }
  reverse(arr2.begin(), arr2.end());
  vector<int> ans;
  for(int i=0;i<min(arr1.size(), arr2.size());++i) {
    if(arr1[i]==arr2[i]) ans.push_back(arr1[i]);
  }
  if(ans.size()>K) return 0;
  for(int i=0;i<ans.size();++i) cout<<ans[i]+1<<endl;
}

