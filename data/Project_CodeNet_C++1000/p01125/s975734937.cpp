#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<functional>
#include<stack>
#include<list>
#include<string>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define INF INT_MAX/3
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int,int>
#define PCC pair<char,char>
#define PCI pair<char,int>
#define PIC pair<int,char>
#define MP make_pair
#define DEBUG(x) cout<<#x<<": "<<x<<endl;


int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)break;
		PII mine = MP(10, 10);
		vector <PII> jem;
		REP(i, n)
		{
			int x, y;
			cin >> x >> y;
			PII temp = MP(x, y);
			jem.push_back(temp);
		}
		int m;
		bool ans = true;
		cin >> m;
		REP(i, m)
		{
			char com;
			int value;
			cin >> com >> value;
			if (com == 'N' || com == 'S')
			{
				if (com == 'S')value = -value;
				REP(j, n)
				{
					if (jem[j].first != mine.first)continue;
					int a = min(mine.second, mine.second + value);
					int b = max(mine.second, mine.second + value);
					if (a <= jem[j].second&&jem[j].second <= b)
					{
						jem[j].first = -1;
						jem[j].second = -1;
					}
				}
				mine.second += value;
			}
			else
			{
				if (com == 'W')value = -value;
				REP(j, n)
				{
					if (jem[j].second != mine.second)continue;
					int a = min(mine.first, mine.first + value);
					int b = max(mine.first, mine.first + value);
					if (a <= jem[j].first&&jem[j].first<= b)
					{
						jem[j].first = -1;
						jem[j].second = -1;
					}
				}
				mine.first += value;
			}
		}
		REP(i, n) 
		{ 
			if (jem[i].first != -1)
			{
				ans = false;
				break;
			}
		}
		if (ans)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}