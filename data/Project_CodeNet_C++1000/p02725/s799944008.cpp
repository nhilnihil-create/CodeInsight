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
  int K, N;
  cin>>K>>N;
  int A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  vector<int> sa(N);
  for(int i=0;i<N;++i) {
    if(i==N-1) sa[i] = K - (A[N-1] - A[0]);
    else sa[i] = A[i+1] - A[i];
  }
  sort(sa.begin(), sa.end(), greater<int>());
  cout<<K-sa[0]<<endl;
}

