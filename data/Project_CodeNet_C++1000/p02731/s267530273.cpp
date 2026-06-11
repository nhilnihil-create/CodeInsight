#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <bit>
#include <time.h>
#include <bitset>
#include <iomanip>
#include <queue>
typedef long long int ll;
using namespace std;

int main() 
{
	int L; cin >> L;
	double d = (double)L / 3;
	d = pow(d, 3);
	cout << setprecision(8)<<d << endl;
}