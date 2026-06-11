#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <unordered_map>
#include <map>
#include <numeric>
#include <limits>
#include <utility>
#include <queue>
#include <random>
#include <bitset>
#include <memory>
#include <complex>
#include<fstream>
#include <chrono>
using namespace std;
typedef long long LL;


int main(void)
{
	/*
	chrono::system_clock::time_point start, end;
	start = chrono::system_clock::now();
	end = chrono::system_clock::now();
	double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	//printf("time %lf[ms]\n", time);
	*/

	LL D;
	LL man=0;
	
	vector<int> c(27);
	vector<LL> last(27,0);
	cin >>D;
	for (int i = 1; i <= 26; i++) {
		cin >>c[i];
	}
	vector<vector<LL>> s(D+1,vector<LL>(27,0));
	vector<LL> t(D+1);
	for (int i = 1; i <= D; i++) {
		for (int j = 1; j <= 26; j++) {
			cin >>s[i][j];
		}
	}
	for (int i = 1; i <= D; i++) {
		cin >>t[i];
	}

	for (int i = 1; i <= D; i++) {
		LL dis = 0;
		man+=s[i][t[i]];
		last[t[i]] = i;
		for (int j = 1; j <= 26; j++) {
			dis+=(c[j]*(i-last[j]));
		}
		man-=dis;
		cout <<man<<endl;
	}
	return 0;
}
