#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>

//#include <map>

using namespace std;

int main()
{
	vector<string> vStr;

	while (1)
	{	
		string st;
		getline(cin, st);
		if (st == string("0 0"))break;
		vStr.push_back(st);
	}

	for (int i = 0; i < vStr.size(); i++)
	{
		vector<int> tv;

		while (vStr.at(i).find(' ') != -1)
		{
			tv.push_back(stoi(vStr.at(i).substr(0, vStr.at(i).find(' '))));
			vStr.at(i).erase(0, vStr.at(i).find(' ') + 1);
		}
		tv.push_back(stoi(vStr.at(i)));
		vStr.at(i) = "";
		
		sort(tv.begin(), tv.end());

		for (int j = 0;; j++)
		{
			char ch[20];
			sprintf(ch, "%d", tv.at(j));
			vStr.at(i) += ch;
			if (j == tv.size() - 1)break;
			vStr.at(i) += " ";
		}
	}

	for (int i = 0; i < vStr.size(); i++)
	{
		cout << vStr.at(i) << endl;
	}
	return 0;
}