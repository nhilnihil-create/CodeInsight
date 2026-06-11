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
	
	ll arr[N], tmp;
	REP(i, 0, N){
		cin >> tmp;
		if( i == 0) arr[0] = tmp;
		else arr[i] =  arr[i-1] + tmp;
	}
	
	ll ans = pow(10, 18);
	REP(i, 0, N-1){
		ans = min(ans, abs(arr[N-1] - 2*arr[i]));
	}
	cout << ans;
		

}
