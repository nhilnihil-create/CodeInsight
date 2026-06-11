#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

vector<int> v;

int main(void){
	int n,i,m=0;
	cin >> n;
	for(i=0; i<20; ++i){
		if(n==(1<<i)){
			cout << "No" << endl;
			return 0;
		}else if(n<(1<<i)){
			break;
		}
		m = max(m,(1<<i));
	}
	cout << "Yes" << endl;
	cout << 1+n << " " << 2+n << endl;
	for(i=2; i<n; i+=2){
		cout << 1 << " " << i << endl;
		cout << 1 << " " << i+1 << endl;
		cout << i << " " << i+1+n << endl;
		cout << i+1 << " " << i+n << endl;
	}
	if(n%2==0){
		cout << m << " " << n << endl;
		cout << (n^m^1) << " " << n+n << endl;
	}
	return 0;
}
