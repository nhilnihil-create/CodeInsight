#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
#include<array>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<list>
#define _USE_MATH_DEFINES

#include<math.h>
#include<unordered_map>

#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

class Flood
{
public:
	int startStep;
	int volume;
};

int main()
{
	vector<Flood> floods;
	Flood flood;
	int memo[50000];

	string input;
	cin >> input;

	int nowFloor;
	int nowStep;

	nowFloor = 25000;
	nowStep = 0;

	for (int i = 0; i < 50000; i++)
	{
		memo[i] = -1;
	}

	memo[nowFloor] = nowStep;
	flood.startStep = nowStep;
	flood.volume = 0;

	for (char c : input)
	{
		nowStep++;
		switch (c)
		{
		case '\\':
			nowFloor++;
			memo[nowFloor] = nowStep;
			if (flood.volume != 0)
			{
				floods.push_back(flood);
				flood.volume = 0;
			}
			break;
		case '/':
			nowFloor--;
			if (memo[nowFloor] != -1)
			{
				flood.volume += (nowStep - memo[nowFloor] - 1);
				flood.startStep = memo[nowFloor];
				while (floods.size() != 0)
				{
					if (flood.startStep < floods.back().startStep)
					{
						flood.volume += floods.back().volume;
						floods.pop_back();
					}
					else
					{
						break;
					}
				}
			}
			memo[nowFloor] = nowStep;
			break;
		case '_':
			memo[nowFloor] = nowStep;
			break;
		default:
			cout << "illegal input" << endl;
		}
	}

	if (flood.volume != 0)
	{
		floods.push_back(flood);
		flood.volume = 0;
	}

	int sum = 0;

	for (int i = 0; i != floods.size(); i++)
	{
		sum += floods[i].volume;
	}

	cout << sum << endl;
	cout << floods.size();
	
	for (int i = 0; i != floods.size(); i++)
	{
		if (i == 0)
		{
			cout << " ";
		}
		cout << floods[i].volume;
		if (i != (floods.size() - 1))
		{
			cout << " ";
		}
	}
	cout << endl;

	return 0;
}