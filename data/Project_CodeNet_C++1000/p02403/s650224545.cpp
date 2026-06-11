#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#define _USE_MATH_DEFINES

#include<math.h>

#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

int main()
{
	int n;
	vector<int> a, b;
	
	while (true)
	{
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		if (ta == 0 && tb == 0)
		{
			break;
		}
		else
		{
			a.push_back(ta);
			b.push_back(tb);
		}
	}

	for (int i = 0; i != a.size(); i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			for (int k = 0; k < b[i]; k++)
			{
				printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}