#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define PI 3.141592653589793



int main(){
  int N, K, C; cin >> N >> K >> C;
  string S; cin >> S;
  vector<int> L, R; int prev = -inf;
  rep(i, N){
    if(S[i]=='o' && i-prev>C){
      prev = i; L.push_back(i);
    }
  }
  prev = inf;
  for(int i=N-1; i>=0; i--){
    if(S[i]=='o' && prev-i>C){
      prev = i; R.push_back(i);
    }
  }
  if(L.size()!=K || R.size()!=K){
    return 0;
  }
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());
  rep(i, K){
    if(L[i]==R[i]){
      cout << L[i]+1 << endl;
    }
  }
}