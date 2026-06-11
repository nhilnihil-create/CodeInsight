#include<iostream>
#include<algorithm>
using namespace std;
static const int NIL = -1;
static const int MAX_A = 16;
static const int MAX_B = 16;

int a, b;
int n, x, y;
int memo[MAX_A][MAX_B];

int main(){
	for(;;){
		cin >> a >> b;
		if(a == 0 && b == 0) break;
		
		fill(memo[0], memo[a], 0);
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> x >> y;
			x--; y--;
			memo[x][y] = NIL;
		}
		memo[0][0] = 1;
		
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				if(memo[i][j] == NIL) continue;
				if(i == 0){
					if(memo[i][j - 1] == NIL) memo[i][j] = 0;
					else memo[i][j] += memo[i][j - 1];
				}else if(j == 0){
					if(memo[i - 1][j] == NIL) memo[i][j] = 0;
					else memo[i][j] += memo[i - 1][j];
				}else{
					if(memo[i][j - 1] == NIL && memo[i - 1][j] == NIL) memo[i][j] = 0;
					else if(memo[i][j - 1] == NIL) memo[i][j] += memo[i - 1][j];
					else if(memo[i - 1][j] == NIL) memo[i][j] += memo[i][j - 1];
					else memo[i][j] += memo[i - 1][j] + memo[i][j - 1];
				}
			}
		}

		cout << memo[a - 1][b - 1] << endl;
	}
	return 0;
}
