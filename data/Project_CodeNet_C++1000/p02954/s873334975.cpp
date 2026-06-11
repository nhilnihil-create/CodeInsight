#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	string abc;
	vector<int> cou(1000000, 0);
	int count = 0;
	cin >> abc;

	for (int i=0;;i++)
	{
		if (i + 1 == abc.length() - 1)
		{
			//cout << cou[i - count] << endl;
			//cout << cou[i - count-1] << endl;
			//cout << count << endl;
			if (abc[i] == 'R')
			{
				cou[i] += count / 2 + 1;
				cou[i + 1] += count - count / 2 + 1;
				count = 0;
				break;
			}

			if (abc[i] == 'L')
			{
				i++;
				count++;
				cou[i - count] += count / 2;
				cou[i - (count + 1)] += count - count / 2;
				count = 0;
				break;
			}
		}

		if (abc[i] != abc[i + 1])
		{
			

			if (abc[i] == 'R')
			{
				cou[i] += count / 2 + 1;
				cou[i + 1] += count - count / 2 + 1;
				count = 0;
				continue;
			}

			if (abc[i] == 'L')
			{
				cou[i-count] += count / 2;
				cou[i - (count + 1)] += count - count / 2;
				count = 0;
				continue;
			}

		}
		count++;
	}

	for (int i = 0;i < abc.length();i++)
	{
		cout << cou[i] << ' ';
	}
	cout << endl;
}