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
	ll K;
	cin >> N >> K;
	vector<ll> A(N), F(N);// 計算に使うんでllにします
	for(int i=0; i<N; i++) cin >> A[i];
	for(int i=0; i<N; i++) cin >> F[i];

	sort(A.rbegin(), A.rend());
	sort(F.begin(), F.end());
	ll left = -1, right = 1e12+1;
	while(right - left > 1){
		ll mid = (left+right) / 2;
		bool is_ok = true;
		// ll sumK = 0;
		// for(int i=0; i<N; i++){
		// 	sumK += max(A[i]-mid/F[i], (ll)0);
		// }
		// if(sumK > K) is_ok = false;
		ll tmpK = K;
		for(int i=0; i<N; i++){
			tmpK -= max(A[i] - mid/F[i], (ll)0);
		}
		if(tmpK < 0) is_ok = false;

		
		if(is_ok) right = mid;
		else left = mid;
		// cout << " left: " << left << " mid: " << mid << " right: " << right << endl;
	}
	cout << right << endl;
	return 0;
}

