#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<iterator>
#include<complex>
#include<stack>
using namespace std;
string s;
using MIte = multimap<int, int>::iterator;




int main() {
	long N, K;
	cin >> N >> K;

	if (K == 1) {
		cout << "0" << endl;
	}
	else {
		cout << N - K << endl;
	}

	return 0;
}