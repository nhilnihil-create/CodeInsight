#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

long long MOD = 1000000000 + 7;

bool compare(pii x, pii y){
  return x.second < y.second;
}

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  vector<pii> v(N);
  for(int i = 0; i < N; i++){
    ll tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    v.at(i) = make_pair(tmp1-tmp2, tmp1+tmp2);
  }
  sort(v.begin(), v.end(), compare);

  vector<ll> l(N), r(N);
  for(int i = 0; i < N; i++){
    l[i] = v.at(i).first;
    r[i] = v.at(i).second;
  }

  int ans = 1;
  ll now = r[0];
  for(int i = 1; i < N; i++){
    if(l[i] < now){
      // 残せない
    } else { 
      ans++;
      now = max(now, r[i]);
    }
  }
  cout << ans << endl;


}
