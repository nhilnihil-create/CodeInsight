#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string.h>
#define REP(i,j,n) for(int i=j;i<n;i++)
#define SORT(x) sort(x.begin(),x.end())

using namespace std;



int main() {
	REP(i, 1, 10) {
		REP(j, 1, 10) {
			cout << i << "x" << j << '=' << i*j << endl;
		}
	}
	
	return 0;
}