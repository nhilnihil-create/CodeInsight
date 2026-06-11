#include <bits/stdc++.h>
using namespace std;
#define min(a, b) ((a<b)?a:b)
#define max(a, b) ((a<b)?b:a)
#define pb push_back
#define endl "\n"
typedef long long ll;

#define max_element mmmmm
#define min_element nnnnn

#define int long long

template<class T>
class BIT {
	public:
		int BIT_size;
		vector<T> BIT_array;
		BIT(int BIT_size) {
			this->BIT_size = BIT_size;
			BIT_array = vector<T>(BIT_size+1);
			fill(BIT_array.begin(), BIT_array.end(), 0);
		}
		void BIT_update(int i, T d) {
			for(; i<=BIT_size; i+=(i&-i)) {
				BIT_array[i] += d;
			}
		}
		T BIT_sum(int i) {
			T BIT_sum_result = 0;
			for(; i>0; i-=(i&-i)) {
				BIT_sum_result += BIT_array[i];
			}
			return BIT_sum_result;
		}				
};

ll pow(ll a, ll b, ll m) {
	a %= m;
	ll result = 1;
	while(b > 0) {
		if(b & 1) {
			result = result*a%m;
		}
		a = a*a%m;
		b /= 2;		
	}
	return result;
}

signed main() {
	int n; cin >> n;
	vector<int> values;
	set<int> no_repeat;
	map<int, vector<int>> m;
	for(int i=0; i<n; i++) {
		int x; cin >> x;
		m[x].push_back(i);
		values.push_back(x);
		no_repeat.insert(x);
	}
	sort(values.begin(), values.end());
	reverse(values.begin(), values.end());
	int pos[n];
	for(int i=0; i<n; i++) {
		pos[i] = m[values[i]][0];
		m[values[i]].erase(m[values[i]].begin());
	}
	int dp[n+1][n+1];
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) dp[i][j] = 0;
	}
	for(int len = 1; len <= n; len++) {
		for(int i=0; i<=len; i++) {
			int j = len - i;
			//cout << "ij " << i << " " << j << endl;
			if(i > 0) {
				dp[i][j] = max(dp[i][j], 
				dp[i-1][j]+abs(pos[i+j-1]+1-i)*values[i+j-1]);
				//cout << "A " << pos[i+j-1]+1-i << " " <<
				//values[i+j-1] << endl;
			}
			if(j > 0) {
				dp[i][j] = max(dp[i][j],
				dp[i][j-1]+abs(pos[i+j-1]-(n-j))*values[i+j-1]);
				//cout << "B " << pos[i+j-1]+1-j << " " << 
				//values[i+j-1] << endl;
				
			}
			//cout << dp[i][j] << endl;
		}
	}
	int solution = 0;
	for(int i = 0; i <= n; i++) solution = max(solution, dp[i][n-i]);
	cout << solution << endl;
	return 0;
}





































































