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
	int n; string s;
	cin >> n >> s;
	int ans = 0;
	for(int ss = 0; ss < n; ss++){
		string si = s.substr(ss, n-ss);
		vector<int> z(si.size());
		int i = 1, j = 0;
		while(i < si.size()) {
			while(i+j < (int)si.size() && si[j]==si[i+j]) j++;
			
			z[i] = j;

			if(j==0) {
				i++;
				continue;
			}

			int k = 1;
			while(k < j && k + z[k] < j) {
				z[i+k] = z[k];
				k++;
			}

			i += k;
			j -= k;
		}
		for(i = 1; i < (int)si.size(); i++) {
			if(i >= z[i]) {
				chmax(ans, z[i]);
			}
		}
	}
	cout << ans << endl;
}