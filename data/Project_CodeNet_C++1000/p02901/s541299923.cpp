#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int INF = 1001001001;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> key(m);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		key[i].second = ai;
		rep(j, bi) {
			int ki;
			cin >> ki;
			ki--;
			key[i].first |= (1 << ki);
		}
	}
	vector<int> dp(1 << n,INF);
	dp[0] = 0;
	rep(i, m) {
		for (int bit = 0; bit < (1 << n); bit++) {
			dp[bit | key[i].first] = min(dp[bit | key[i].first], dp[bit] + key[i].second);
		}
	}
    if(dp[(1<<n)-1]!=INF){
	  cout << dp[(1 << n) - 1] << endl;
    }else{
      cout<<-1<<endl;
    }
}