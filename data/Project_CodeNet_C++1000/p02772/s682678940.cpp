#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() 
{
	int a,b=0;
	cin >> a;
	vector<int>x(a);
	for (int i = 0; i < a; i++)
	{
		cin >> x[i];
	}

	for (int i = 0; i < a; i++)
	{
		if (x[i] % 2 == 0)
		{
			if (x[i] % 3 == 0 || x[i]%5==0)
			{

			}
			else
			{
				b++;
			}
		}
	}

	if (b > 0)
	{
		cout << "DENIED" << endl;;
	}
	else
	{
		cout << "APPROVED"<<endl;
	}
	



}
