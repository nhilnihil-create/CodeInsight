#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,k;
  cin >> n >> k;
  if((n-1)*(n-2)/2<k){
    cout << -1 << endl;
    return 0;
  }
  int m = n-1+(n-1)*(n-2)/2-k;
  cout << m << endl;
  rep(i,n-1)cout << 1 << " " << i+2 << endl;
  int add = (n-1)*(n-2)/2-k;
  for(int i=2;i<n;i++){
    for(int j=i+1;j<n+1;j++){
      if(add==0)return 0;
      cout << i << " " << j << endl;
      add--;
    }
  }
  return 0;
}
