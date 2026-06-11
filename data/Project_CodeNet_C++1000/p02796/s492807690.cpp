#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 

int main(){
  int N; cin >> N;
  ll X, L;
  vector<pair<ll,ll>> UD(N);
  rep(i,N){
    cin >> X >> L;
    UD[i] = {X+L, X-L};
  }
  sort(all(UD));

  int cnt = 0;
  ll U=UD[0].first;
  rep(i,N){
    if (i==0) cnt++;
    else if (UD[i].second < U) continue;
    else {
      cnt++;
      U = UD[i].first;
    }
  }

  cout << cnt << endl;

  
  return 0;
}
