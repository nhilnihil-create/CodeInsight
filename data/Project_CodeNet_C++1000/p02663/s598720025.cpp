#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
int main() {
	int H1, M1, H2, M2, K;
	cin >> H1 >> M1 >> H2 >> M2 >> K;
	int fast = H1 * 60 + M1;
	int second = H2 * 60 + M2;
	cout << second - fast - K << endl;
	return 0;
}

