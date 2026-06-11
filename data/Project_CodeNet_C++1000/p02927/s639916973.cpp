#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int m,d;cin>>m>>d;
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= d; j++) {
			int d1 = j / 10;
			int d2 = j % 10;
			if (d1 >= 2 && d2 >= 2 && i == d1 * d2){
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}