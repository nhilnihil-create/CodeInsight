#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;

vector<ll> memo(51, 0);

int 
main()
{

  int N, K; cin >> N >> K;
  vector<int> arr(N, 0);
  rep(i, 0, N) cin >> arr[i];

  sort(arr.begin(), arr.end(), greater<int>());
  ll ans = 0;
  rep(i, K, N){
    ans += arr[i];
  }

  cout << ans << endl;

}