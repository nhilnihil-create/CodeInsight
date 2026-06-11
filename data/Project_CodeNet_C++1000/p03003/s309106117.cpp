#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5 + 2e3;
const int mod = 1e9+7;
int n,m;
int a[maxn] , b[maxn] ;
LL f[maxn][maxn];

void Read(){
	
//	#define TASK "ABC"
//	freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++) cin >> a[i] ;
	for(int i=1 ; i<=m ; i++) cin >> b[i] ;
	
}
void Magic(){
	
	f[0][0] = 1;
	for(int i=1 ; i<=max(n,m) ; i++) f[i][0] = 1 , f[0][i] = 1;
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			f[i][j] = ( f[i-1][j] + f[i][j-1] - f[i-1][j-1] + mod) % mod;
			if (a[i] == b[j]) f[i][j] = ( f[i][j] + f[i-1][j-1] ) % mod;
		}
	}
	
}
void Write(){
	cout << f[n][m] ;
}
int main(){
    
    Read();
    Magic();
    Write();
    
    return 0;
}
