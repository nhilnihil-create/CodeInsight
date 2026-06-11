#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int P, Q, R;
	cin >> P >> Q >> R;

	int a = P + Q;
	int b = P + R;
	int c = Q + R;

	cout << min({ a,b,c }) << endl;
	
}