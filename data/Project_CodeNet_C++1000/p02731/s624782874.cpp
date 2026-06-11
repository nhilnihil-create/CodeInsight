#include <bits/stdc++.h>
#define SIZE 10
#define PI 3.141592653589793

using namespace std;
typedef long long ll;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int i,j;
	int tmp;
	int counter=0;
	double N;
	double answer=0;
	vector<int> given;

	cin >> N;

	answer=(N/3)*(N/3)*(N/3);
	cout << std::fixed << std::setprecision(15) << answer << endl;

	return 0;
}

