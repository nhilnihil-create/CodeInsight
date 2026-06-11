#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <numeric>
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <fstream>
using namespace std;

int main()
{
//	cut here before submit 
//	freopen("testcase.int", "r", stdin);
	string str = "";
	int x = 600;
	
	while ( getline (cin, str )){
		int d;
		stringstream ss(str);
		ss >> d;
		int i;
		int sum = 0;
		for (i = d; i < x; i += d){
			sum += i*i*d;
		} // end for
		cout << sum << endl;
	} // end for

	return 0;
}