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


int main(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	int l = 0, r = 0;
	char pre;
	int ans = 0;
	if(s[0]=='L'){pre='L';}
	else {pre='R';}
	int cnt = 1;
	srep(i,1,n){
		if(pre==s[i]){
			cnt++;
			continue;
		}
		else if(pre=='L'){
			ans += cnt - 1;
			l++;
			pre = 'R';
			cnt = 1;
		}
		else {
			ans += cnt - 1;
			r++;
			pre='L';
			cnt = 1;
		}
	}
	ans += cnt - 1;
	if(pre=='L')l++;else r++;
	int a = min(l, r);
	if(k >= a){
		ans = n-1;
	}else{
		ans += 2*k;
	}
	cout << ans << endl;
}