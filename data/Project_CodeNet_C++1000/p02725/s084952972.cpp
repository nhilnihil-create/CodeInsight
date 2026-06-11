#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll K; int N; cin >> K >> N;


  ll max_val = 0;

  vector<ll> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  for(int i = 1; i < N; i++){
    max_val = max(max_val, abs(v[i] - v[i-1]));
  }

  max_val = max(max_val, v[0] + K - v[N-1]);

  cout << K - max_val << endl;
}

