#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> pi;
typedef pair<int,int> vi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(vi c, vi d){
	return c.S < d.S;
}

int main() {
	ll N;
	cin >> N;
	
	ll arr[N], l[N], r[N];
	REP(i, 0, N) cin >> arr[i];
	
	REP(i, 0, N){
		if(i == 0) l[0] = arr[i];
		else{
			l[i] = arr[i] + l[i-1];
		}
	}
	for(int i = N-1; i >= 0; i--){
		if(i == N-1) r[i] = arr[i];
		else{
			r[i] = arr[i] + r[i+1];
		}
	}
	
	ll ans = pow(10, 18);
	REP(i, 0, N-1){
		//cout << ans << " " << l[i] << " " << r[i+1] << " " << i << endl;
		ans = min(ans, abs(l[i]-r[i+1]));
	}
	cout << ans;
		

}
