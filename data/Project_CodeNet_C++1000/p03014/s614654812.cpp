#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int h, w;
char grid[2002][2002];
int num[4][2002][2002];

void search(){
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			if (grid[i][j] == '.'){
				num[0][i][j] = num[0][i][j-1] + 1;
				num[1][i][j] = num[1][i-1][j] + 1;
			}else{
				num[0][i][j] = 0;
				num[1][i][j] = 0;
			}
		}
	}
	for (int i = h; i >= 1; i--){
		for (int j = w; j >= 1; j--){
			if (grid[i][j] == '.'){
				num[2][i][j] = num[2][i][j+1] + 1;
				num[3][i][j] = num[3][i+1][j] + 1;
			}else{
				num[2][i][j] = 0;
				num[3][i][j] = 0;
			}
		}
	}
	return;
}

int main(){
	cin >> h >> w;
	for (int i = 0; i < 2002; i++){
		for (int j = 0; j < 2002; j++){
			grid[i][j] = '#';
		}
	}
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			cin >> grid[i][j];
		}
	}

	search();

	int ans = 0;
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			int sum = 0;
			for (int k = 0; k < 4; k++){
				sum += num[k][i][j];
			}
			ans = max(ans, sum-3);
		}
	}

	cout << ans << endl;

	return 0;
}