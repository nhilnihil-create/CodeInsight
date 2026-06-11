#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 2005;
char s[N][N];
int u[N][N], d[N][N], l[N][N], r[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int h, w;
	cin>>h>>w;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin>>s[i][j];
		}
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(s[i][j] == '#'){
				u[i][j] = 0;
				l[i][j] = 0;
			}else{
				u[i][j] = 1 + (i?u[i - 1][j]:0);
				l[i][j] = 1 + (j?l[i][j - 1]:0);
			}
		}
	}
	for(int i = h - 1; i >= 0; i--){
		for(int j = w - 1; j >= 0; j--){
			if(s[i][j] == '#'){
				d[i][j] = 0;
				r[i][j] = 0;
			}else{
				d[i][j] = 1 + ((i + 1 != h)?d[i + 1][j]:0);
				r[i][j] = 1 + ((j + 1 != w)?r[i][j + 1]:0);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(s[i][j] == '#')continue;
			ans = max(ans, l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);
		}
	}
	cout<<ans<<'\n';

	return 0;
}