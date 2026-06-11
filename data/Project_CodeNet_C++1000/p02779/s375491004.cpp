#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N;
  cin >> N;
  map<int,int> cnt;
  rep(i,N){
    int a;
    cin >> a;
    cnt[a]++;
  }

  if(cnt.size() == N) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}
