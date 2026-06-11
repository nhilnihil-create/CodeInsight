#include <iostream>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
signed main() {
	int N, K, R, S, P; string T;string W=""; cin >> N >> K >> R >> S >> P >> T;
	int D = 0;
	for (int X = 0; X < N; X++) {
		if (X < K) {
			if (T[X] == 'r') {
				D += P;
				W.push_back('p');
			}
			else if (T[X] == 's') {
				D += R;
				W.push_back('r');
			}
			else {
				D += S;
				W.push_back('s');
			}
		}
		else if (T[X] != T[X - K]) {
			if (T[X] == 'r') {
				D += P;
				W.push_back('p');
			}
			else if (T[X] == 's') {
				D += R;
				W.push_back('r');
			}
			else {
				D += S;
				W.push_back('s');
			}
		}
      else{
        T[X]='a';
      }
	}
	cout << D << endl;
}