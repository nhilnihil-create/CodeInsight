#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N,M; cin >> N >> M;
  ll sum = 0;
  for(ll i = 0; i < M; i++){
    ll tmp; cin >> tmp;
    sum += tmp;
  }
  cout << ( (N >= sum) ? (N - sum) : -1) << endl;
}
