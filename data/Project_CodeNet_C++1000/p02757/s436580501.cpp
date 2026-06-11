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
	int N, P;
	cin >> N >> P;
	string S;
	cin >> S;
	reverse(S.begin(), S.end());//*pow(10, i)したときにiがindexと一致するようにする
  if(P==2 || P==5){
		ll ans = 0;
		for(int i=0; i<N; i++){
			if((S[i]-'0')%P !=0) continue;
			//ans += i+1;
      ans += N-i;
		}
		cout << ans << endl;
		return 0;
	}

	

	int wa = 0;//累積和
	int pow_10_i = 1;// pow(10, i)%P
	map<int, int> mp;
	ll ans = 0;
	for(int i=0; i<N; i++){
		mp[wa]++;
		wa += (S[i]-'0')*pow_10_i;
		wa %= P;
		ans += mp[wa];
		pow_10_i = pow_10_i * 10 % P;
	}


	cout << ans << endl;


}
