#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
using graph = vector<vector<int>>;

const double pi = 3.14159265358979323846;
const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	rep(i,n){
		int tmp; cin >> tmp;
		sum += tmp;
		a.at(i) = tmp;
	}
	sum /= 2;

	for(int i = n - 2; i >= 1; i -= 2){
		sum -= a.at(i);
	}
	vector<ll> ans(n);
	ans.at(0) = 2 * sum;
	for(int i = 1; i < n; i++){
		ans.at(i) = 2*(a.at(i-1)-ans.at(i-1)/2);
	}
	for(int i = 0; i < n; i++){
		cout << ans.at(i) << " ";
	}
} 