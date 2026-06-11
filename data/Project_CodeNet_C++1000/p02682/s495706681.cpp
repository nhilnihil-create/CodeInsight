#include <iostream>
# include <math.h>

using namespace std;

int main()
{
	int A, B, C, K;

	cin >> A >> B >> C >> K;

	int sum = 0;

	if (K > A)
	{
		sum += A;
		K -= A;
	}
	else
	{
		sum += K;
		goto end;
	}
	if (K > B)
		K -= B;
	else
		goto end;
	if (K > C)
	{
		sum -= C;
	}
	else
	{
		sum -= K;
	}

end:
	cout << sum;

	return 0;
}