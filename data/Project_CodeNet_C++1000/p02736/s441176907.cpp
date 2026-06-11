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

string s;

int main(void){
	int n,i,j,k=0;
	bool flag = false;
	cin >> n;
	cin >> s;
	for(i=0; i<n; ++i){
		s[i] -= '1';
		if(s[i]==1){
			flag = true;
		}
		k += s[i]*(((n-1)&i)==i);
		k %= 2;
	}
	if(k || flag){
		cout << k << endl;
		return 0;
	}
	k = 0;
	for(i=0; i<n; ++i){
		s[i] /= 2;
		k += s[i]*(((n-1)&i)==i);
		k %= 2;
	}
	cout << (k*2) << endl;
	return 0;
}
