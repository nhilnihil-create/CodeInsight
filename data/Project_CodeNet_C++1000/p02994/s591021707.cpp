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
  int N, L;
  cin>>N>>L;
  vector<int> arr(N);
  for(int i=0;i<N;++i) arr[i] = L+i;
  int num = inf;
  for(int i=0;i<N;++i) {
    if(abs(num)>abs(arr[i])) num = arr[i];
  }
  int ans = 0;
  for(int i=0;i<N;++i) {
    if(arr[i]==num) continue;
    ans += arr[i];
  }
  cout<<ans<<endl;
}

