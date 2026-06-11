#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n;
	int count = 0;
	double prob;
	
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		int temp = i;
		if(temp%2!=0)
		{
			count++;
		}
	}
	
	prob = count/n;
	
	cout << fixed << showpoint;
	cout << setprecision(10) << prob << endl;
	
return 0;
}