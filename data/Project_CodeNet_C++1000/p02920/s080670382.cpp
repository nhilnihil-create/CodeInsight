#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define REP(i, n) for(int i = 0; i < (n); i++)
using namespace std;

typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	// 入力

	int n;
	cin >> n;
	int sn = 1 << n;
	vector<int> model(sn);
	REP(i, sn) cin >> model[i];

	//

	// 処理

	sort(model.begin(), model.end());
	vector<int> slime;
	slime.push_back(model.back());
	model.back() = -1;
	REP(i, n)
	{
		vector<int> s = slime;
		sort(s.begin(), s.end());
		int k = sn - 1;
		while (s.size() > 0 && k >= 0) 
		{
			if (model[k] == -1)
			{
				k--;
				continue;
			}
			if (model[k] < s.back())
			{
				slime.push_back(model[k]);
				s.pop_back();
				model[k] = -1;
			}
			k--;
		}
		if (s.size() > 0)
		{
			cout << "No";
			return 0;
		}
	}

	//

	// 出力

	cout << "Yes";

	//

	return 0;
}
