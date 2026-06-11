#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	/*int n;
	cin >> n;
	if (n % 2 == 0)cout << n / 2;
	else cout << n / 2 + 1;*/

	int bingo[3][3];
	for(int i=0;i<3;i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> bingo[i][j];
		}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int b = 0;
		cin >> b;
		for(int j=0;j<3;j++)
			for (int k = 0; k < 3; k++)
			{
				if (bingo[j][k] == b)bingo[j][k] = -1;
			}
	}
	
	for (int i = 0; i < 3; i++) {
		int ans = 0;
		for (int j = 0; j < 3; j++)
		{
			if (bingo[i][j] == -1)ans += 1;
			if (ans == 3) { cout << "Yes"; exit(0); }
		}
		ans = 0;
		for (int j = 0; j < 3; j++)
		{
			if (bingo[j][i] == -1)ans += 1;
			if (ans == 3) { cout << "Yes"; exit(0); }
		}
	}
	int dog = bingo[0][0] + bingo[1][1] + bingo[2][2];
	if(dog==-3) { cout << "Yes"; exit(0); }
	int cat = bingo[0][2] + bingo[1][1] + bingo[2][0];
	if(cat==-3) { cout << "Yes"; exit(0); }
	cout << "No";
	return 0;
}

