#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll T[2],A[2],B[2];
	cin >> T[0] >> T[1];
	cin >> A[0] >> A[1];
	cin >> B[0] >> B[1];
	if((T[0]*A[0] + T[1] * A[1]) == (T[0]*B[0]+T[1]*B[1])){
		cout << "infinity" << endl;
		return 0;
	}
	ll k1 = T[0]*(A[0]-B[0]);
	ll k2 = T[1]*(A[1]-B[1]);
	if( (k1>0 && k2>0) || (k1<0&&k2<0) ){
		cout << "0" << endl;
		return 0;
	}
	if( abs(k1) > abs(k2)){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	if(k1>0){
		k1 *= -1;
		k2 *= -1;
	}
	if((-k1)%(k1+k2)){
		ans =(-k1)/(k1+k2) * 2LL + 1;
	}else ans = (-k1)/(k1+k2) * 2LL;
	cout << ans << endl;
}