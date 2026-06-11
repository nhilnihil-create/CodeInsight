#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string First;
	string Second;
	int Judge = 0;
	vector<int> Inner_judge(100, 1);

	cin >> First;
	cin >> Second;

	for(int i = 0; i < First.size(); i++)
	{
		for(int j = 0; j < Second.size(); j++)
		{
			if(Second[j] != First[(i+j) % First.size()]) Inner_judge[i] = 0;
		}
		if(Inner_judge[i] == 1) Judge = 1;
	}

	if(Judge == 0) cout << "No" << endl;
	if(Judge == 1) cout << "Yes" << endl;

	return 0;
}