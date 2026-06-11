#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

const int maxn = 2e6+5;
int ans[maxn];

void solve(){
	string s;
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n; i++){
		int l = i;
		while(i+1<n&&s[i]==s[i+1]){
			i++;
		}
		int len = i - l + 1;
		if(s[l]=='L') {
			ans[l] += (len+1)/2;
			ans[l-1]+= len/2;
		}else{
			ans[i] += (len+1)/2;
			ans[i+1] += len/2;
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] <<" ";
	}
  	cout << '\n';
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}