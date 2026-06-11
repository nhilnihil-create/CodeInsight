#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl;
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   " << endl;
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}
 

int main(){
  ll N, M;
  cin >> N >> M;
  vector<ll> H(N), A(M), B(M);
  vector<vector<ll>> vec(N, vector<ll>());
  for(int i=0; i<N; i++) cin >> H[i];
  for(int i=0; i<M; i++){
      ll a, b;
      cin >> a >> b;
      a--; b--;
      A[i] = a;
      B[i] = b;
      vec[a].push_back(b);
      vec[b].push_back(a);
  }

  vector<bool> is_highest(N, true);
  for(int i=0; i<N; i++){
    if(is_highest[i] == false) continue;
    bool is_tall = true;
    for(int j=0; j<vec[i].size(); j++){
      if(H[i] <= H[vec[i][j]]){
        is_tall = false;
      }
      else if(H[i] > H[vec[i][j]]) is_highest[vec[i][j]] = false;
    }
    if(is_tall == false) is_highest[i] = false;

  }

  ll ans = 0;
  for(int i=0; i<N; i++){
      if(is_highest[i] == true) ans++;
  }
  cout << ans << endl;
    
}
