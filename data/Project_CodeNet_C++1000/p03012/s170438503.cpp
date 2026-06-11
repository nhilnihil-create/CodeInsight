#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int n = 0;
	cin >> n;
	vector <int> vect(n);
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (i == 0)
		{
			vect[i] = temp;
		}
		else
		{
			vect[i] = vect[i - 1] + temp;
		}
	}
	int t1 = vect[n - 1] - vect[0] - vect[0];
	if (t1 < 0)
	{
		t1 = t1 * -1;
	}
	int t2 = 0;
	for (int i = 1; i < n-1; i++)
	{
		t2 = vect[n - 1] - vect[i] - vect[i];
		if (t2 < 0)
		{
			t2 = t2 * -1;
		}
		if (t2 < t1)
		{
			t1 = t2;
		}
	}
	cout << t1 << endl;
	return 0;
}
