#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int a[4], b[4];
	while(cin >> a[0] >> a[1] >> a[2] >> a[3] && cin >> b[0] >> b[1] >> b[2] >> b[3]){
		int A[10] = {0}, B[10] = {0}, h = 0, br = 0;
		for (int i = 0; i < 4; ++i)
		{
			A[a[i]]++;
			B[b[i]]++;
		}
		for (int i = 0; i < 4; ++i)
		{
			if (a[i] == b[i]){
				h++;
				A[a[i]]--;
				B[b[i]]--;
			}
			//cout << a[i]  << b[i] << endl;
		}
		for (int i = 0; i < 10; ++i)
		{
			if(A[i] == 1 && B[i] == 1){
				br++;
			}
		}
		cout << h << ' ' << br << endl;
	}
}