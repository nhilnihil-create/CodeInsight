#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<int,int>;

template <class _T> inline bool chmax (_T& a,_T b){if(a<b){a=b;return true;}return false;}
template <class _T> inline bool chmin (_T& a,_T b){if(a>b){a=b;return true;}return false;}

const long long INF = 1LL << 60;

bool dp[110][10100] = {false};

int main(void){
	int a,b,m;cin >> a >> b >>m;
	vector<int>A(a),B(b);
	int ans_a=1000000,ans_b = 1000000,ans=1000000;
	rep(i,a){
		cin >> A[i];
		ans_a = min(ans_a,A[i]);
	}
	rep(i,b){
		cin >> B[i];
		ans_b = min(ans_b,B[i]);
	}
	ans = ans_a+ans_b;
	rep(i,m){
		int x,y,z;
		cin >> x >> y >> z;
		ans = min(ans,A[x-1]+B[y-1]-z);
	}
	cout << ans << endl;
	return 0;
}
