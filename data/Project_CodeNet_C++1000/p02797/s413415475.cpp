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
  ll N, K, S;
  cin>>N>>K>>S;
  if(S==(int)1e9) {
    for(int i=0;i<K;++i) cout<<S<<" ";
    for(int i=K;i<N;++i) cout<<1<<" ";
    cout<<endl;
  }
  else {
    for(int i=0;i<K;++i) cout<<S<<" ";
    for(int i=K;i<N;++i) cout<<(int)1e9<<" ";
    cout<<endl;
  }
}

