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
  int N;
  cin>>N;
  ll H[N];
  for(int i=0;i<N;++i) cin>>H[i];
  int ans=0;
  int tmp=0;
  for(int i=0;i<N-1;++i) {
    if(H[i]>=H[i+1]) tmp++;
    else {
      ans = max(ans, tmp);
      tmp = 0;
    }
  }
  ans = max(ans, tmp);
  cout<<ans<<endl;
}

