#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int H1, M1, H2, M2, K;
	cin >> H1 >> M1 >> H2 >> M2 >> K;

	cout << (H2 - H1) * 60 + M2 - M1 - K << endl;

}
