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
  int N, M;
  cin>>N>>M;
  int s[M], c[M];
  for(int i=0;i<M;++i) {
    cin>>s[i]>>c[i];
    s[i]--;
  }
  int ans = -1;
  string tmp;
  bool can;
  for(int i=0;i<1000;++i) {
    tmp = to_string(i);
    if(tmp.size()!=N) continue;
    can = true;
    for(int j=0;j<M;++j) {
      if(tmp.size()<=s[j]) {
        can = false;
        break;
      }
      if(tmp[s[j]]!=c[j]+'0') can = false;
    }
    if(can) {
      ans = i;
      break;
    }
  }
  cout<<ans<<endl;
}

