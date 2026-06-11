#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
	int x, n;
	cin >> x >> n;
	vector<bool> vec(101,true);
	for(int i=0; i<n; i++){
		int p; cin >> p;
		vec[p] = false;
	}
	int dx = 0;
	int ans;
	while(1){
		if(x-dx < 0){
			ans = x-dx;
			break;
		}
		else if(vec[x-dx]){
			ans = x-dx;
			break;
		}
		else if(x+dx > 100){
			ans = x+dx;
			break;
		}
		else if(vec[x+dx]){
			ans = x+dx;
			break;
		}
		dx++;
	}
	cout << ans << endl;

	return 0;
}