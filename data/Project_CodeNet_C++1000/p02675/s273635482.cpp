

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;


const int BIG_NUM = 1e8;

int main() {
	int n;
	cin >> n;

	switch (n%10)
	{
	case 3:
		cout << "bon" << endl;
		break;

	case 0:
	case 1:
	case 6:
	case 8:
		cout << "pon" << endl;
		break;
	default:
		cout << "hon" << endl;
		break;
	}

}