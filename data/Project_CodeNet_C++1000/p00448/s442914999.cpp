#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;
#define int long long
const int mod = 1000000007;

vector<string> str;

int R, C;
int a[11][10001] = {};

int solve(int p,string c){
	if (p == R){
		str.push_back(c);
		return 0;
	}
	solve(p + 1, c);
	solve(p + 1, c + (char)(p + 48) + ",");
}

signed main()
{
	
	while (1){
		int ans = 0;
		cin >> R >> C;
		if (R == 0 && C == 0) return 0;
		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				cin >> a[i][j];
			}
		}

		solve(0, "");
		for (int i = 0; i < str.size(); i++){
			vector<int> tmp;
			string num = "";
			for (int j = 0; j < str[i].length(); j++){
				if (str[i][j] == ','){
					tmp.push_back(stoi(num));
					num = "";
				}
				else {
					num += str[i][j];
				}
			}

			int score = 0;
			for (int k = 0; k < C; k++){
				int t1 = 0, t2 = 0;
				for (int l = 0; l < R; l++){
					bool flag = false;
					for (int m = 0; m < tmp.size(); m++){
						if (l == tmp[m]){
							flag = true;
							if (a[l][k] == 1) t2++;
							else t1++;
						}
					}
					if (flag == false){
						if (a[l][k] == 1) t1++;
						else t2++;
					}
				}
				score += max(t1, t2);
			}
			ans = max(ans, score);
		}
		cout << ans << endl;
	}
}