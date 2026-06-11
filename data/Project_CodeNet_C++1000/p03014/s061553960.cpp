#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int h, w;
	cin >> h >> w;
	vector<vector<char>> s(h, vector<char>(w));
	rep(i, h){
		rep(j, w){
			cin >> s[i][j];
		}
	}
	
	vector<vector<int>> hor(h, vector<int>(w, 0));
	vector<vector<int>> ver(h, vector<int>(w, 0));
	for(int i = 0; i < h; ++i){
		int count = 0;
		for(int j = 0; j < w; ++j){
			if(s[i][j] == '.'){
				count++;
				hor[i][j] = count;
			}
			else{
				count = 0;
			}
		}
	}
	
	for(int j = 0; j < w; ++j){
		int count = 0;
		for(int i = 0; i < h; ++i){
			if(s[i][j] == '.'){
				count++;
				ver[i][j] = count;
			}
			else{
				count = 0;
			}
		}
	}
	
	for(int i = 0; i < h; ++i){
		bool hold = false;
		int hold_v = 0;
		for(int j = w - 1; j >= 0; --j){
			if(hold){
				if(hor[i][j] == 0){
					hold = false;
				}
				else{
					hor[i][j] = hold_v;
				}
			}
			else{
				if(hor[i][j] != 0){
					hold = true;
					hold_v = hor[i][j];
				}
			}
		}
	}
	
	for(int j = 0; j < w; ++j){
		bool hold = false;
		int hold_v = 0;
		for(int i = h - 1; i >= 0; --i){
			if(hold){
				if(ver[i][j] == 0){
					hold = false;
				}
				else{
					ver[i][j] = hold_v;
				}
			}
			else{
				if(ver[i][j] != 0){
					hold = true;
					hold_v = ver[i][j];
				}
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			ans = max(ans, hor[i][j] + ver[i][j] - 1);
		}
	}
	
	cout << ans << endl;
	return 0;
}

