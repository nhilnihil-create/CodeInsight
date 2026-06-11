#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;

int 
main() {
  ll N; cin >> N;
  vector<ll> arr(N + 1, 0);
  vector<ll> order(N);
  rep(i, 0, N){
    ll tmp; cin >> tmp;
    arr[tmp]++;
    order[i] = tmp;
  }

  vector<ll> comp(N + 1);
  rep(i, 1, N + 1){
    ll num = arr[i];
    comp[i] = num * (num - 1) / 2;
  }

  ll sum = 0;
  rep(i, 1, N + 1) sum += comp[i];

  rep(i, 0, N){
    ll num = arr[order[i]];
    --num;
    ll tmp_comp = num * (num - 1) / 2;
    cout << sum - comp[order[i]] + tmp_comp << endl;
  }
}
