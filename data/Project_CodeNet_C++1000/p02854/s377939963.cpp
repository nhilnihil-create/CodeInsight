#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<ll> v(N);
  vector<ll> a(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }
  if(N == 2){
    cout << abs(v[0] - v[1]) << endl;
    return 0;
  }
  a[0] = v[0];
  for(int i = 1; i < N; i++){
    a[i] = a[i-1] + v[i];
  }
  ll min_val = 1000000000000000000;
  for(int i = 1; i < N-1; i++){
    ll before = a[i];
    ll after = a[N-1] - a[i];
    ll val = abs(after - before);
    min_val = min(min_val, val);
  }
  cout << min_val << endl;


}
