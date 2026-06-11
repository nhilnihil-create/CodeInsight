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
	vector<int> a(N+1);
	a[0] = -1;//
	for(int i=1; i<=N; i++) cin >> a[i];

	vector<int> ans(N+1, 0);
	ans[0] = -1;

	for(int i=N; i>0; i--){
		int sum = 0;
		// N <= 10^5なのでO(N^2)解だと間に合わない
		// for(int j=i+1; j<=N; j++){
		// 	if(j%i == 0){
		// 		if(ans[j] == 1) sum++;
		// 	}
		// }

		//調和級数 なら O(NlogN)なので間に合う
		for(int j=i+i; j<=N; j+=i){
			if(ans[j] == 1) sum++;
		}
		sum %= 2;
		if(a[i] == sum) ans[i] = 0;
		else ans[i] = 1;
	}



	// cout << " ans:"; print_vec(ans);
	int num = 0;
	for(int i=1; i<=N; i++) if(ans[i] == 1) num++;
	cout << num << endl;
	for(int i=1; i<=N; i++) if(ans[i] == 1) cout << i << " ";
	cout << endl;
}

