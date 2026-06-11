# include <iostream>
# include <math.h>

using namespace std;

int main()
{
	double A, B, C, D;
	cin >> A >> B >> C >> D;

	if (ceil(C / B) > ceil(A / D))
		cout << "No";
	else
		cout << "Yes";

	return 0; 
}