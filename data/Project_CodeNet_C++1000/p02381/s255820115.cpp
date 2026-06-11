#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double istdev(vector <int> &nums){
	int n=nums.size();
	double ave;

	int s1 = 0;
	for (int i=0; i<n; i++)
		s1 += nums[i];
	ave = (double)s1/n;

	double s2 = 0;
	for (int i=0; i<n; i++)
		s2 += pow(nums[i]-ave,2);
	return sqrt(s2/n);
}

int main(void)
{
	int n;
	while (cin >> n, n != 0){
		vector <int> s(n);
		for (int i=0; i<n; i++)
			cin >> s[i];

		cout << fixed << istdev(s) << endl;
	}
	return 0;
}