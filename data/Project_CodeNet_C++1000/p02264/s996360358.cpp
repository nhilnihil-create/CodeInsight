#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <functional>
#include <cassert>
#include <iomanip>
#include <array>
#include <time.h>
#include <limits.h>
#pragma comment(lib, "winmm.lib")
#define debug(x) cout<<#x<<": "<<x<<endl
#define rep(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)


using namespace std;

class task{
public:
	string name;
	int time;
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef _WIN32
	istream &cin = ifstream("input.txt");
#endif

	queue<task> Q;
	int n, quantum, sum = 0;

	cin >> n >> quantum;
	string tmp1, tmp2;
	rep(i, n){
		cin >> tmp1 >> tmp2;
		Q.push({ tmp1, stoi(tmp2) });
	}
	while (!Q.empty()){
		if (Q.front().time <= quantum){
			
			sum += Q.front().time;
			cout << Q.front().name << " " << sum << endl;
			Q.pop();
		}
		else{
			sum += quantum;
			string str = Q.front().name; int in = Q.front().time - quantum;
			Q.push({ str, in });
			Q.pop();
		}
	}
	
	return 0;
}