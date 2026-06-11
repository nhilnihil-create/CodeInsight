#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  ll K, Q; cin >> N >> K >> Q;

  vector<ll> v(N,0);

  for(int i = 0; i < Q; i++){
    int tmp; cin >> tmp;
    tmp--;
    v[tmp]++;
  }

  for(int i = 0; i < N; i++){
    if(K - (Q-v[i]) > 0){
      cout << "Yes" << endl;
    } else { 
      cout << "No" << endl;
    }
  }
}
