#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N;
pair<int, int> LR[100000];

signed main(){
	cin >> N;
	rep(i, N){
		int X, L;
		cin >> X >> L;
		LR[i] ={ X-L, X+L };
	}
	sort(LR, LR+N);
	
	int l = INT_MAX;
	int ans = 0;
	for(int i=N-1; i>=0; i--){
		if(LR[i].second <= l){
			ans++;
			l = LR[i].first;
		}
	}
	cout << ans << endl;
}