#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
  
int main()
{
  ll N,K,S;
  cin >> N >> K >> S;

  if(S!=1000000000){
    REP(i,N){
      if(i<K){
        cout << S;
      }else{
        cout << 1000000000;
      }
      if(i!=N-1){
        cout << " ";
      }
    }
    cout << endl;
  }else{
    REP(i,N){
      if(i<K){
        cout << S;
      }else{
        cout << 999999999;
      }
      if(i!=N-1){
        cout << " ";
      }
    }
    cout << endl;
  }
}