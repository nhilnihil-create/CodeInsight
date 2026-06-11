#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main(){
	int n, m, l;
	vector< vector<long> > matlix1, matlix2, ans;
	cin >> n >> m >> l;
	for(int y = 0; y < n; y++){
		vector<long> tmp;
		for(int x = 0; x < m; x++){
			long num;
			cin >> num;
			tmp.push_back(num);
		}
		matlix1.push_back(tmp);
	}
	for(int y = 0; y < m; y++){
		vector<long> tmp;
		for(int x = 0; x < l; x++){
			long num;
			cin >> num;
			tmp.push_back(num);
		}
		matlix2.push_back(tmp);
	}
	for(int i = 0; i < n; i++){
		vector<long> tmp;
		for(int j = 0; j < l; j++){
			long mul = 0;
			for(int k = 0; k < m; k++){
				mul += matlix1[i][k] * matlix2[k][j];
			}
			tmp.push_back(mul);
		}
		ans.push_back(tmp);
	}
	for(int y = 0; y < n; y++){
		for(int x = 0; x < l; x++){
			cout << ans[y][x];
			if(x < l - 1) cout << ' ';
		}
		if(y < n) cout << '\n';
	}
}

