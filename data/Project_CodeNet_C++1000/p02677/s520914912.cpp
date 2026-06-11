#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <cmath>
#define ll long long

using namespace std;

const double pi = 3.14159265358979323846;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, H, M;

	cin >> A >> B >> H >> M;


	double hours = ((double)(M)) / (60.0) + H;

	double hourHandDegree = hours / (12.0) * 360;

	double minHandDegree = hours / (1.0) * 360;


	double angle = hourHandDegree > minHandDegree ? hourHandDegree - minHandDegree : minHandDegree - hourHandDegree;

	//angle = angle / 360;
	angle = angle * pi / (180.0);


	double c = sqrt(A * A + B * B - 2 * A * B * cos(angle));

	cout << std::setprecision(10000000) << c << endl;




	return 0;
}