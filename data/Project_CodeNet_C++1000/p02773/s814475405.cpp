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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  map<string, int> amap;
  string tmp;
  vector<string> arr;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    if(amap[tmp]==0) arr.push_back(tmp);
    amap[tmp]++;
  }
  int num = 0;
  for(int i=0;i<arr.size();++i) {
    num = max(num, amap[arr[i]]);
  }
  vector<string> ans;
  for(int i=0;i<arr.size();++i) {
    if(amap[arr[i]]==num) ans.push_back(arr[i]);
  }
  sort(ans.begin(), ans.end());
  for(int i=0;i<ans.size();++i) cout<<ans[i]<<endl;
}

