# include <bits/stdc++.h>
# define ll long long int
# define ld long double
# define pb push_back
# define mp make_pair
# define mod 1000000007
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
// online submission
	#endif
	IOS
	int r,c,k;
	cin >> r >> c >> k;
	char arr[r+1][c+1] = {'a'};
	int row[r][c+1] = {0}, col[r+1][c] = {0};
	int tot = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> arr[i][j];
			if(arr[i][j] == '#')
				tot++;
		}
	}
	for(int i = 0; i < r; i++){
		row[i][0] = (arr[i][0] == '#');
		for(int j = 1; j <= c; j++){
			row[i][j] = row[i][j - 1] + (arr[i][j] == '#');
		}
	}
	for(int j = 0; j < c; j++){
		col[0][j] = (arr[0][j] == '#');
		for(int i = 1; i <= r; i++){
			col[i][j] = col[i - 1][j] + (arr[i][j] == '#');
		}
	}
	int ways = 0;
	for(int i = 0; i < (1 << r ); i++){	//Change was made here: (1 << r + 1) --> (1 << r)
		int x = 0;
		vector<int> tempx;
		for(int j = 0; j < r; j++){
			if((i & (1 << j))){
				tempx.pb(j);
				x += row[j][c];
			}
		}
		for(int j = 0; j < (1 << c); j++){	//Change was made here: (1 << c + 1) --> (1 << c)
			int y = 0;
			vector<int> tempy;	
			for(int t = 0; t < c; t++){
				if((j & (1 << t))){
					y += col[r][t];
					tempy.pb(t);
				}
			}
			if(tempx.size() > 0 && tempy.size() > 0){
				for(int a : tempx){
					for(int b : tempy){
						y -= (arr[a][b] == '#');
					}
				}
			}
			if(tot - x - y == k){
				// if(tempx.size() > 0 && tempy.size() > 0){
				// 	for(int a : tempx){
				// 		for(int b : tempy){
				// 			cout << a << " " << b << endl;
				// 		}
				// 	}
				// }
				ways++;
				// cout << ways << " --------------XXX--------------\n";
			}
		}
	}
	cout << ways;
	return 0;
}