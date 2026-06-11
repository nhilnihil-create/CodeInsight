#include <iostream>

using namespace std;

int main()
{
	int score_a[4];
	int score_b[4];
	int sum_a, sum_b;
	
	cin >> score_a[0] >> score_a[1] >> score_a[2] >> score_a[3];
	cin >> score_b[0] >> score_b[1] >> score_b[2] >> score_b[3];
	sum_a = score_a[0] + score_a[1] + score_a[2] + score_a[3];
	sum_b = score_b[0] + score_b[1] + score_b[2] + score_b[3];
	
	if (sum_a > sum_b) cout << sum_a << "\n";
	else cout << sum_b << "\n";
	
	return 0;
}