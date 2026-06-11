#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

double Distance(vector<int> vecX, vector<int> vecY, int p)
{
	double dTemp = 0.0;
	double dSum = 0.0;
	for (int i = 0; i < vecX.capacity(); i++)
	{
		dTemp = abs(vecX[i] - vecY[i]);
		dSum += pow(dTemp, p);
	}
	return pow(dSum, 1.0 / p);
}

int main()
{
	int nMax = 0;
	vector<int> vecX, vecY;
	int nCount = 0;
	cin >> nCount;
	int nTemp, g;
	for (int i = 0; i < nCount; i++)
	{
		cin >> nTemp;
		vecX.push_back(nTemp);
	}
	for (int i = 0; i < nCount; i++)
	{
		cin >> nTemp;
		vecY.push_back(nTemp);
		g = abs(vecX[i] - nTemp);
		if (g > nMax)
		{
			nMax = g;
		}
	}
	cout << fixed << setprecision(6) << Distance(vecX, vecY, 1) << endl;
	cout << fixed << setprecision(6) << Distance(vecX, vecY, 2) << endl;
	cout << fixed << setprecision(6) << Distance(vecX, vecY, 3) << endl;
	cout << fixed << setprecision(6) << nMax << endl;

	//system("pause");
	return 0;
}