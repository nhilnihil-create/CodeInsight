#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <math.h> 
#include <iomanip>
#include <string.h>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define PI 3.14159265358979323846264338327950L

#define INF 0x3f3f3f3f
//const int N = 2e5 + 5;
  
 
int32_t  main() {

	IOS;

	int X;

	cin >> X;
	 
	for (int i = -200; i <= 200; i++) {

		for (int j = -200; j <= 200; j++) {

			int A = pow(i, 5);
			int B = pow(j, 5);

			if ((A - B) == X) {

				cout << i << " " << j << endl;
				return 0;
			}


		}


	}


}
