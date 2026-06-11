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

int a[225816],b[225816];
vector<int> v,u;

int main(void){
	int n,i,m;
	cin >> n;
	for(i=0; i<20; ++i){
		if(n==(1<<i)){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	for(i=1; i<4; ++i){
		v.push_back(i);
	}
	for(i=1; i<4; ++i){
		v.push_back(i+n);
	}
	for(i=4; i+3<=n; i+=4){
		v.push_back(i);
		v.push_back(i+1);
		v.push_back(i+2);
		v.push_back(i+3);
		v.push_back(i+n);
		v.push_back(i+n+1);
		v.push_back(i+n+2);
		v.push_back(i+n+3);

	}
	m = (n/4)*4;
	if(0 < n%4 && n%4 < 3){
		cout << n+m << " " << n+m+1 << endl;
		cout << n+m+1 << " " << 1 << endl;
		cout << 1 << " " << m << endl;
		cout << m << " " << m+1 << endl;
		if(n%4 == 2){
			cout << n+m+1 << " " << n+m+2 << endl;
			cout << m+2 << " " << 2 << endl;
		}
	}else if(n%4==0){
		cout << ((m-4)^m) << " " << (m-4) << endl;
		cout << ((m-4)^m) << " " << n << endl;
		cout << (m-4) << " " << n+n << endl;

	}
	for(i=(v.l_ength()-1); i>0; --i){
		if(n%4==0 && v[i]==(m-4)){
			continue;	
		}
		cout << v[i] << " " << v[i-1] << endl;
	}
	return 0;
}
