#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;

const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> num(n);
	rep(i,n){
		cin >> num.at(i);
	}
	int ans = 0;
	for(int i = 1; i < n - 1; i++){
		if(num.at(i - 1) < num.at(i) && num.at(i) < num.at(i + 1)) ans++;
		else if(num.at(i - 1) > num.at(i) && num.at(i) > num.at(i + 1)) ans++;
	}
	cout << ans << endl;
} 