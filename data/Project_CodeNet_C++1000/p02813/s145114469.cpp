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
  int N;
  cin>>N;
  vector<int> P(N), Q(N);
  for(int i=0;i<N;++i) cin>>P[i];
  for(int i=0;i<N;++i) cin>>Q[i];
  vector<int> arr(N);
  for(int i=0;i<N;++i) arr[i] = i+1;
  int a, b;
  bool cana, canb;
  int index = 0;
  do {
    cana = true;
    canb = true;
    for(int i=0;i<N;++i) {
      if(arr[i]!=P[i]) cana = false;
    }
    for(int i=0;i<N;++i) {
      if(arr[i]!=Q[i]) canb = false;
    }
    if(cana) a = index;
    if(canb) b = index;
    index++;
  }while(next_permutation(arr.begin(), arr.end()));
  cout<<abs(a-b)<<endl;
}

