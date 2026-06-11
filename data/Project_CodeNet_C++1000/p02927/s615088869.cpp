#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int m,d;
	cin >> m >> d;
	int cnt = 0;
	for(int i=1;i<=m;i++){
		for(int j=10;j<=d;j++){
			if(i==j%10 * (j/10%10) && j%10>=2 && (j/10%10)>=2 ){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}