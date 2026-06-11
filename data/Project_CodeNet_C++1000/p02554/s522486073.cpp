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

ll mypow(ll a, ll b) {
  ll ans = 1;
  ll tmp;
  ll two;
  while(b>0) {
    two = 1;
    tmp = a;
    while(2*two<b) {
      tmp *= tmp;
      tmp %= mod;
      two *= 2;
    }
    b -= two;
    ans *= tmp;
    ans %= mod;
  }
  return ans;
}

int main() {
  int N;
  cin>>N;
  cout<<(mypow(10, N)-2*mypow(9, N)%mod+mod+mypow(8, N))%mod<<endl;
}

