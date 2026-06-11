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
  string S; cin >> S;
  int Q; cin >> Q;
  bool flag = true;

  rep(i, 0, Q){
    int tmp; cin >> tmp;
    if(tmp == 1){
      flag = !flag;
    } else {
      int F; cin >> F;
      string add; cin >> add;
      if(F == 1){
        if(flag) S.insert(0, add);
        else S.append(add);
      } else {
        if(flag) S.append(add);
        else S.insert(0, add);
      }
    }
  }

  if(flag){
    cout << S << endl;
  } else {
    reverse(S.begin(), S.end());
    cout << S << endl;
  }

}