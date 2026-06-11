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
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

int main(){
	int N;
	cin >> N;
	vector<ll> A(N);
	for(int i=0; i<N; i++) cin >> A[i];

	vector<ll> ans(N, 0);
	for(int i=0; i<N; i++){
		if(i%2 == 0) ans[0] += A[i];
		else 	ans[0] -= A[i];
	}
	ans[0] /= 2;

	for(int i=1; i<N; i++){
		ans[i] = A[i-1] - ans[i-1];
	}

	for(int i=0; i<N; i++){
		cout << 2*ans[i] << " ";
	} cout << endl;

}

