#include<iostream>
#include<vector>
using namespace std;

bool judge(vector<int> a, vector<int> b) {
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] < a[i - 1]) return false;
	}
	for (int i = 1; i < b.size(); i++)
	{
		if (b[i] < b[i - 1]) return false;
	}
	return true;
}

int main() {

	int num;
	int data[10];
	vector<int> a, b;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		
		for (int j = 0; j < 10; j++)
		{
			cin >> data[j];
		}
		int j;
		for (j = 0; j <= 1024 ; j++)
		{
			a.clear();
			b.clear();
			for (int k = 0; k < 10; k++)
			{
				if ((j >> k) & 1)
				{
					a.push_back(data[k]);
				}
				else
				{
					b.push_back(data[k]);
				}
			}
			if (judge(a,b))
			{
				cout << "YES" << endl;
				break;
			}
		}
		if (j==1025)
		{
			cout << "NO" << endl;
		}

	}
	//system("pause");
	return 0;
}