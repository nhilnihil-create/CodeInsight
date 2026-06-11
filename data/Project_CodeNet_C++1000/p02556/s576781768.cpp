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
  vector<ll> arr1(N), arr2(N);
  ll x, y;
  for(int i=0;i<N;++i) {
    cin>>x>>y;
    arr1[i] = x+y;
    arr2[i] = x-y;
  }
  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());
  cout<<max(arr1[N-1]-arr1[0], arr2[N-1]-arr2[0])<<endl;
}

