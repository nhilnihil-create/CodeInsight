#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 3e5+5;

int row[N], column[N];
set<pair<int,int>> targets;

int main()
{
	int H, W;
	scanf("%d%d",&H,&W);
	int M; 
	scanf("%d",&M);
	for(int i=1;i<=M;i++)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		row[a]++;
		column[b]++;
		targets.insert({a,b});
	}

	
	vector<pair<int,int>> R, C;
	for(int i=1;i<=H;i++) R.emplace_back(row[i],i);
	for(int i=1;i<=W;i++) C.emplace_back(column[i],i);

	sort(R.begin(), R.end());
	sort(C.begin(), C.end());

	int mx_R = R.back().first;
	int mx_C = C.back().first;

	int res = mx_R + mx_C - 1;

	for(auto it_R = R.end()-1;it_R->first==mx_R;it_R--)
	{
		for(auto it_C = C.end()-1;it_C->first==mx_C;it_C--)
		{
			if(targets.count({it_R->second, it_C->second}) == 0)
			{
				res = mx_R + mx_C;
				break;
			}
		}
	}

	printf("%d\n",res);
}
