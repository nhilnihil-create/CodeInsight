#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;


int main()
{
	int N;
	vector<vector<int> > Aij(3, vector<int>(3, 0));
	set<int> s_list;
	rep(i, 3) {
		rep(j, 3) {
			cin >> Aij[i][j];
			s_list.insert(Aij[i][j]);
		}
	}
	
	cin >> N;
	vector<int> Bi(N, 0);
	rep(i, N) {
		cin >> Bi[i];
		auto it = s_list.find(Bi[i]);
		if (it != s_list.end()){ 
			rep(j, 3) {
				rep(k, 3) {
					if (Aij[j][k] == Bi[i]) Aij[j][k] = -1;
				}
 			}
		}
	}

	bool judge = false;
	bool judges[8] = {true,true,true,true,true,true,true,true};
	rep(i, 3){
		if (Aij[i][0] != -1) judges[0] = false;
		if (Aij[i][1] != -1) judges[1] = false;
		if (Aij[i][2] != -1) judges[2] = false;
		if (Aij[0][i] != -1) judges[3] = false;
		if (Aij[1][i] != -1) judges[4] = false;
		if (Aij[2][i] != -1) judges[5] = false;
		if (Aij[i][i] != -1) judges[6] = false;
		if (Aij[2-i][i] != -1) judges[7] = false;
	}

	rep(i, 8) {
		if (judges[i] == true) {
			judge = true;
		}
	}

	if (judge) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
} 