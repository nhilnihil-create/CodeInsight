#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
  int N, K, C;
  cin>>N>>K>>C;
  string S;
  cin>>S;
  map<int, int> amap;
  map<int, int> ans;
  for(int i=0;i<N;++i) {
    if(S[i]=='o') {
      amap[i]++;
      i += C;
    }
  }
  reverse(S.begin(), S.end());
  for(int i=0;i<N;++i) {
    if(S[i]=='o') {
      amap[N-1-i]++;
      i += C;
    }
  }
  int num = 0;
  for(int i=0;i<N;++i) {
    if(amap[i]==2) num++;
  }
  if(num>K) return 0;
  for(int i=0;i<N;++i) {
    if(amap[i]==2) cout<<i+1<<endl;
  }
}

