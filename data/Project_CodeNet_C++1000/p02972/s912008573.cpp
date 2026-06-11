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
	vector<int> a(N+1, 0);
	for(int i=1; i<=N; i++) cin >> a[i];

	vector<bool> is_putonBall(N+1, false);
	for(int i=N; i>=1; i--){
		int sum = 0;
		for(int j=i+i; j<=N; j+=i){
			if(is_putonBall[j]) sum++;
		}
		if(sum%2 != a[i]) is_putonBall[i] = true;
	}

	int ans = 0;
	for(int i=1; i<=N; i++) ans += is_putonBall[i];
	cout << ans << endl;
	for(int i=1; i<=N; i++) if(is_putonBall[i]) cout << i << " ";
	cout << endl;
}

