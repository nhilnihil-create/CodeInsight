#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
	int r, c;
	cin >> r >> c;
	vector<vector<int>> v(r, vector<int>(c));
	for(auto &vv:v) for(auto &a:vv) cin >> a;
	for(auto &vv:v) vv.emplace_back(accumulate(vv.begin(), vv.end(), 0));
	vector<int> puni(c + 1);
	for(int i = 0; i < c; i++) for(int j = 0; j < r; j++) puni[i] += v[j][i];
	for(int i = 0; i < c; i++) puni[c] += puni[i];
	v.emplace_back(puni);
	for(int i = 0; i < r + 1; i++){
		for(int j = 0; j < c + 1; j++){
			if(j) cout << ' ';
			cout << v[i][j];
		}
		cout << endl;
	}
}