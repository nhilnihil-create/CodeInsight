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
    int N;
    cin >> N;
    vector<ll> A(N), wa(N), sa(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
      wa[i] = A[i] + i;
      sa[i] = A[i] - i;
    }

    sort(wa.begin(), wa.end());
    sort(sa.begin(), sa.end());

    ll ans = 0;
    for(int i=0; i<N; i++){
      auto iter1 = lower_bound(wa.begin(), wa.end(), -sa[i]);
      //auto index1 = iter1 - wa.begin();
      auto iter2 = upper_bound(wa.begin(), wa.end(), -sa[i]);
      //auto index2 = iter2 - wa.begin();

      ans += iter2 - iter1;
    }

    cout << ans << endl;

}
