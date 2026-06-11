#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;
int MAXI = 1e8 + 1;

bool
comp(pair<ll, ll> a, pair<ll, ll> b)
{
  return a.first < b.first;
}

int 
main()
{
  ll N, D, A; cin >> N >> D >> A;
  vector<pair<ll, ll>> enmy(N);
  ll a = 0;
  rep(i, 0, N){
    ll x, h; cin >> x >> h;
    if(a < h) a= h;
    enmy[i].first = x;
    if(h % A != 0) enmy[i].second = (h / A) + 1;
    else enmy[i].second = h / A;
  }

  sort(enmy.begin(), enmy.end(), comp);
  
  vector<ll> range(N + 1, 0);
  rep(i, 0, N){
    ll dis = enmy[i].first + D * 2;
    auto itr = upper_bound(enmy.begin(), enmy.end(), make_pair(dis, 0), comp);
    if((itr - enmy.begin())<= N - 1){
      if(dis < enmy[i + 1].first){ range[i] = -1;
      //} else if(dis == enmy[i + 1].first){ range[i] += i + 1;
      //if(dis == enmy[i + 1].first){ range[i] += i + 1;
      //} else if(dis < enmy[i + 1].first){ range[i] = -1;//
      }else range[i] = itr - enmy.begin() - 1;
    } else {
       range[i] = N;}
  }

  ll cnt = enmy[0].second;
  vector<ll> current_dm(N + 1, 0);
  current_dm[0] = enmy[0].second;
  if(range[0] == -1) current_dm[1] -= enmy[0].second;
  else current_dm[range[0] + 1] -= enmy[0].second;

  rep(i, 0, N){
    if(current_dm[i] < enmy[i].second){
      ll dm = enmy[i].second - current_dm[i];
      cnt += dm;
      current_dm[i] += dm;
      if(range[i] == -1)current_dm[i + 1] -= dm;
      //else current_dm[range[i]] -= dm; 
      else{
       //if(i == range[i] -1) current_dm[range[i] + 1] -= dm;
       //else current_dm[range[i] + 1] -= dm;
       current_dm[range[i] + 1] -= dm;
      }
    }
      current_dm[i + 1] += current_dm[i];

  }

  cout << cnt << endl;

}