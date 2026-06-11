#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

int x;
bool isbeki[1010];

int main() {
    int n,ans=0;
	cin >> n;
	for (int i = 0;i <= n;i++){
		if (int(i*1.08) == n){
			ans = i;
		}
	}
	if(ans) cout << ans << endl;
	else cout << ":(" << endl;

}