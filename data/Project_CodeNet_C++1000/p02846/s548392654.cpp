#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << endl
#else
#define debug(x)
#endif
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

ll T1, T2, A1, A2, B1, B2;
ll d;

signed main(){

	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
	if(A1 > B1){
		swap(A1, B1);
		swap(A2, B2);
	}
	d = (T1*A1+T2*A2) - (T1*B1+T2*B2);
	if(d == 0){
		cout << "infinity" << endl;
		return 0;
	}
	if(d < 0){
		cout << 0 << endl;
		return 0;
	}
	
	if((T1*B1-T1*A1)%d == 0) cout << (T1*B1-T1*A1)/d*2 << endl;
	else cout << (T1*B1-T1*A1)/d*2 + 1 << endl;
}

/*
1 1
2 3
3 1
*/