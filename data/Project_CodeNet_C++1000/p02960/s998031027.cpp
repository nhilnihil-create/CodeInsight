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
#include<bitset>
#include<cassert>

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

void print(vector<long long int> a){
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

ll mod_ = 1e9 + 7;
ll mod = 13;

ll pow_(ll x, long long int n){
	ll res(1);
	while(n){
		if(n&1){
			res = ((res%mod) * (x%mod))%mod;
		}
		n >>= 1;
		x = ((x%mod) * (x%mod))%mod;
	}
	return res%mod;
}


int main(){
	string s;
	cin >> s;
	reverse(all(s));
	int n = s.size();
	vector<vector<ll>> dp(n + 1, vector<ll>(mod, 0));
	dp[0][0] = 1;
	rep(i,n){
		int c = (s[i] == '?' ? -1 : s[i] - '0');
		rep(j, 10)
		{
			if(c != -1 && c != j)
				continue;
			ll now = (j * pow_(10, i)) % mod;
			rep(k, mod)
			{
				dp[i + 1][(k + now) % mod] += dp[i][k];
				dp[i + 1][(k + now) % mod] %= mod_;
			}
		}
	}
	cout << dp[n][5] % mod_ << endl;

	return 0;
}