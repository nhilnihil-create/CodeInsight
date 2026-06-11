#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>  
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
#define int long long 
	while (true) {
		int a, l;
		cin >> a >> l;
		if (a == 0) return 0;
		map<int,int> going;
		going[a] = 0;
		for (int i = 1; i >= 0; ++i) {
			int gogo[10] = {};
			int now = a;
			for (int q = 0; q < l; ++q) {
				gogo[now % 10]++;
				now /= 10;
			}
			int maxi = 0, mini = 0;
			for (int i = 0; i < 10; ++i) {
				REP(q, gogo[i]) {
					mini *= 10;
					mini += i;
				}
			}
			for (int i = 9; i >= 0; --i) {
				REP(q, gogo[i]) {
					maxi *= 10;
					maxi += i;
				}
			}
			a = maxi - mini;
			if (going.find(a) != going.end()) {
				cout << going[a] << " " << a << " " << i - going[a] << endl;
				break;
			}
			going[a] = i;
		}
	}
}

