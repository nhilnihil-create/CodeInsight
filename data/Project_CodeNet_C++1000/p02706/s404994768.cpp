#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <math.h> 
#include <iomanip>
#include <string.h>
#include<sstream>
#include <vector>
#include <set>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define PI 3.14159265358979323846264338327950L

#define INF 0x3f3f3f3f
//const int N = 2e5 + 5;

 
 


int32_t  main() {

	IOS;
  
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {

		int tmp;

		cin >> tmp;

		N -= tmp;

	}

	if (N < 0) {
		cout << "-1" << endl;
	}
	else {
		cout << N << endl;
	}
}