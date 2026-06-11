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
	int N, X, Y;
	cin >> N >> X >> Y;
	X--; Y--;

	vector<ll> ans(N+1, 0);//cnt[k]:歩数kかかる組み合わせ
	for(int s=0; s<=N-2; s++){
		for(int g=s+1; g<=N-1; g++){
			ll steps1 = g - s;//XYの道を使わない歩数
			ll steps2 = abs(s-X) + 1 + abs(Y-g); //XYの道を使う歩数
			ll mn = (steps1 < steps2) ? steps1 : steps2;
			ans[mn]++;
		}
	}

	for(int i=1; i<=N-1; i++){
		cout << ans[i] << endl;
	}

}
