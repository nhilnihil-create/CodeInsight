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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  int a[N][N];
  bool tmp1, tmp2;
  for(int i=0;i<N-1;++i) {
    for(int j=i+1;j<N;++j) {
      for(int k=0;k<1000;++k) {
        tmp1 = (i&(1<<k));
        tmp2 = (j&(1<<k));
        if((tmp1!=0 && tmp2==0) || (tmp1==0 && tmp2!=0)) {
          a[i][j] = k+1;
          break;
        }
      }
    }
  }
  for(int i=0;i<N-1;++i) {
    for(int j=i+1;j<N;++j) {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}

