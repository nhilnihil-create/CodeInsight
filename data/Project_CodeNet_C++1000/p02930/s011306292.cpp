#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

using vi=vector<int>;


void prt(vi&v, int n)
{
	for(int i=0;i+1<n;i++) printf("%d ", v[i]);
	printf("%d\n", v[n-1]);
}


int main(void)
{
	int n;

	while(scanf("%d", &n)==1)
	{
		vi v={1};

		for(int i=2;n-1>v.size();i++)
		{
			vi t=v;
			v.push_back(i);
			copy(t.begin(), t.end(), back_inserter(v));
		}

		for(int i=n-1;i>0;i--)
		{
			prt(v, i);
		}
	}
	return 0;
}
