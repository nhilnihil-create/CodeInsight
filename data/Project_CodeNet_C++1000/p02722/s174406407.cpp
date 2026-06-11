//#include <bits/stdc++.h>
#include "bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<ll> enum_divisor(ll x){
	ll tmp = x;
	vector<ll> res;
	for(ll i=1; i*i<=x; i++){
		if(tmp%i == 0){
			res.push_back(i);
			if(i*i != tmp) res.push_back(tmp/i);//iが√tmpのときは重複して数えないようにする
		} 
	}
	return res;
}

int main(void) {
	ll N;
	cin >> N;

	ll ans = 0;
	
	//操作1ができる場合
	vector<ll> n_divisor = enum_divisor(N);//Nの約数
	//cout << " n_divisor: ";print_vec(n_divisor);
	for(ll K : n_divisor){
		if(K==1) continue;//K=1だと永遠と操作1ができてしまう
		ll tmp = N;
		while(tmp >= K){//操作1をやれるだけ，やる.
		if(tmp % K == 0) tmp = tmp / K;
		else break;
		}
		if(tmp%K == 1) ans++;//操作2で1になるならインクリメント
		//if(tmp%K == 1) cout << " K: " << K << endl;
	}///↑上のifのところは　操作1に戻ることはないので，これで十分


	//操作1ができない場合(　N%i==1　⇒　(N-1)%i==0)
	// 操作2で1になるのは (N-1)の約数の個数だね
	vector<ll> n1_divisor = enum_divisor(N-1);//(N-1)の約数
	//cout << " n1_divisor: ";print_vec(n1_divisor);
	ans += n1_divisor.size() - 1;//-1は約数1の分(K=1は答えには，あてはまらない)

	cout << ans << endl;
}
