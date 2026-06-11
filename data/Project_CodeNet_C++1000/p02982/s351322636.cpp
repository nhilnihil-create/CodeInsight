#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
int main()
{
	int n, d;
	cin >> n >> d;
	vector<vector<int>> x(n,vector<int>(d));
	rep(i,n)rep(j,d) cin >> x[i][j];

	int ans = 0;
	rep(i,n){
		For(j,i+1,n){
			// 点i と 点jを比較する
			ll sum = 0;
			rep(k,d){
				ll tmp = x[i][k] - x[j][k];
				tmp *= tmp;
				sum += tmp;
			}
			for(int l = 1; l * l <= sum; l++){
				if(l*l == sum) ans++;
			}
		}
	}
	cout << ans << endl;
}
