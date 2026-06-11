#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	set<int> N;
	N.insert(A);
	N.insert(B);
	N.insert(C);

	if (N.size() == 2) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
}