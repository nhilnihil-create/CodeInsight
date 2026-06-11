#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;

void solve()
{
	int N;
	while(cin >> N, N)
	{
		int xMin = 0;
		int xMax = 0;
		int yMin = 0;
		int yMax = 0;
		vector<PP> Vec;
		Vec.push_back(PP(0, P(0, 0)));
		--N;
		int count = 0;
		while(N--)
		{
			int n, d;
			cin >> n >> d;
			++count;
			for(int i = 0; i < Vec.size(); ++i)
			{
				if(Vec[i].first == n)
				{
					if(d == 0)
					{
						Vec.push_back(PP(count, P(Vec[i].second.first - 1, Vec[i].second.second)));
						if(Vec[i].second.first - 1 < xMin)
						{
							xMin = Vec[i].second.first - 1;
						}
					}
					else if(d == 1)
					{
						Vec.push_back(PP(count, P(Vec[i].second.first, Vec[i].second.second - 1)));
						if(Vec[i].second.second - 1 < yMin)
						{
							yMin = Vec[i].second.second - 1;
						}
					}
					else if(d == 2)
					{
						Vec.push_back(PP(count, P(Vec[i].second.first + 1, Vec[i].second.second)));
						if(Vec[i].second.first + 1 > xMax)
						{
							xMax = Vec[i].second.first + 1;
						}
					}
					else if(d == 3)
					{
						Vec.push_back(PP(count, P(Vec[i].second.first, Vec[i].second.second + 1)));
						if(Vec[i].second.second + 1 > yMax)
						{
							yMax = Vec[i].second.second + 1;
						}
					}
					break;
				}
			}
		}
		cout << xMax - xMin + 1 << " " << yMax - yMin + 1 << endl;
	}
}

int main()
{
	solve();
	return(0);
}