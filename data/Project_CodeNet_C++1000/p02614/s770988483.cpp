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

char grid[6][6];
int h, w, k;

bool is_ok(vector<int>&vec1, vector<int>&vec2){
	int coun = 0;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			if (vec1[i] != 0 && vec2[j] != 0){
				if (grid[i][j] == '#') coun++;
			}
		}
	}
	if (coun == k) return true;
	return false;
}

int main(){
	cin >> h >> w >> k;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin >> grid[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < (1<<h); i++){
		vector<int> vec1;
		for (int j = 0; j < h; j++){
			if (i & (1<<j)){
				vec1.push_back(1);
			}else{
				vec1.push_back(0);
			}
		}
		for (int j = 0; j < (1<<w); j++){
			vector<int> vec2;
			for (int k = 0; k < w; k++){
				if (j & (1<<k)){
					vec2.push_back(1);
				}else{
					vec2.push_back(0);
				}
			}
			if (is_ok(vec1, vec2)) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}