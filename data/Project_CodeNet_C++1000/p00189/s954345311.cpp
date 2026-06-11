#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector< vector<int> >
#define vi vector<int>
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define pi 3.14159265359
#define shosu(X) fixed << setprecision(X)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const int INF = 1e9;
int data[20][20];
int main(){
	while(1){
		int n;
		cin >> n;
		if(n == 0) break;
		REP(i,20) REP(j,20) data[i][j] = INF;
		REP(i,20) data[i][i] = 0;
		int m = 0;
		REP(i,n){
			int a,b,c;
			cin >> a >> b >> c;
			m = max(m, a+1); m = max(m, b+1);
			data[a][b] = c;
			data[b][a] = c;
		}
		REP(k,m){
			REP(i,m){
				REP(j,m){
					data[i][j] = min(data[i][j], data[i][k] + data[k][j]);
				}
			}
		}
		int sum[20] = {0};
		int nowmin = INF;
		int ans;
		REP(i,m){
			REP(j,m){
				// cout << data[i][j] << " ";
				sum[i] += data[i][j];
			}
			if(nowmin > sum[i]) {
				nowmin = sum[i];
				ans = i;
			}
		}
		cout << ans << " " << sum[ans] << endl;
	}
}