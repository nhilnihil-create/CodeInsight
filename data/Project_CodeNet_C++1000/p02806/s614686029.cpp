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
  string S[N];
  int t[N];
  for(int i=0;i<N;++i) {
    cin>>S[i]>>t[i];
  }
  string X;
  cin>>X;
  bool ok = false;
  int ans = 0;
  for(int i=0;i<N;++i) {
    if(ok) {
      ans += t[i];
    }
    if(S[i]==X) ok = true;
  }
  cout<<ans<<endl;
}

