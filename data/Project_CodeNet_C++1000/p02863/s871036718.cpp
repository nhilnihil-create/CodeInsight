#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;


void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}



int main() {
	int n, t;
	cin >> n >> t;
	vector<pair<ll, ll>> ab(n);
	rep(i,n){
		int a, b;
		cin >> a >> b;
		ab[i] = pair<ll, ll>(a, b);
	}
	sort(all(ab));
	vector<vector<long long int>> dp(n + 1, vector<long long int>(t, 0));
	rep(i,n){
		rep(j,t){
			if(j-ab[i].first >= 0)
				dp[i + 1][j] = max(dp[i][j], dp[i][j - ab[i].first] + ab[i].second);
			else
				dp[i + 1][j] = dp[i][j];
		}
	}
	ll m = 0;
	rep(i,n){
		m = max(m, dp[i][t - 1] + ab[i].second);
	}
	cout << m << endl;

	return 0;
}