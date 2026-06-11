#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;

bool
comp(pair<ll, ll> a, pair<ll, ll> b)
{
  return a.second < b.second;
}

int 
main()
{
  int N; cin >> N;
  vector<pair<ll, ll>> arr(N);
  rep(i, 0, N){
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr.begin(), arr.end(), comp);

  ll now = 0;
  rep(i, 0, N){
    now += arr[i].first;
    if(now > arr[i].second){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

}