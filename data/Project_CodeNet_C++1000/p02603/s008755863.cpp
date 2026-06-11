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
  int A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  int index = -1;
  for(int i=0;i<N-1;++i) {
    if(A[i]!=A[i+1]) {
      index = i;
      break;
    }
  }
  if(index==-1) {
    cout<<1000<<endl;
    return 0;
  } 
  bool up;
  ll money, kabu;
  if(A[index]<A[index+1]) {
    money = 1000%A[index];
    kabu = 1000/A[index];
    up = true;
  }
  else {
    money = 1000;
    kabu = 0;
    up = false;
  }
  for(int i=index+1;i<N-1;++i) {
    if(up) {
      if(A[i]>A[i+1]) {
        money += kabu*A[i];
        kabu = 0;
        up = false;
      }
    }
    else {
      if(A[i]<A[i+1]) {
        kabu = money/A[i];
        money = money%A[i];
        up = true;
      }
    }
  }
  money += kabu*A[N-1];
  cout<<money<<endl;
}

