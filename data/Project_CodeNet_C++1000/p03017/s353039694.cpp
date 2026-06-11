#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MAX 500010
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N,A,B,C,D;
	cin >> N >> A >> B >> C >> D;
	A--;
	B--;
	C--;
	D--;

	string S;
	cin >> S;

	ll n = S.size();
	repk(i,A,max(C,D)){
		if(S[i] == '#' && S[i+1] == '#'){
			cout << "No" << endl;
			return 0;
		}
	}

	if(C < D){
		cout << "Yes" << endl;
		return 0;
	} 
	else{
		repk(i,B-1,D){
			if(S[i] == '.' && S[i+1] == '.' && S[i+2] == '.'){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
	return 0;
}