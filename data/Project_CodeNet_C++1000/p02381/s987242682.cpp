#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int nCount, nCo;
	while (cin >> nCount, nCount)
	{
		int nInput[1000] = { 0 };
		float nSum = 0;
		int i = 0;
		int nIn = 0;

		nCo = nCount;
		while (nCount--)
		{
			cin >> nIn;
			nInput[i++] = nIn;
			nSum += nIn;
		}
		float nAvg = nSum / nCo;
		nSum = 0;
		for (int i = 0; i < nCo; i++)
		{
			nSum += (nInput[i] - nAvg)*(nInput[i] - nAvg);
		}
		nSum /= nCo;
		nSum = sqrtf(nSum);
		printf("%.5f\n", nSum);
	}
	//system("pause");
	return 0;

}