#include<iostream>
#include<utility>
#include<vector>
#include<cmath>

const double PI = std::acos(-1);

int main() {
	int A, B, H, M;
	std::cin >> A >> B >> H >> M;
	double x = A * std::sin(PI * H / 6 + PI * M / 360) - B * std::sin(PI * M / 30);
	double y = A * std::cos(PI * H / 6 + PI * M / 360) - B * std::cos(PI * M / 30);
	double answer = sqrt(x * x + y * y);
	printf("%.10f\n", answer);
	return 0;
}