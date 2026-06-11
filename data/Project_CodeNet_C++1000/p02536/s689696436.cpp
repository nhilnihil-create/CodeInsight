#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

 map<int,int> ds;	//上下级关系
 //map<int, int> ranks;

int FindSup(int root)
{
	if (ds[root] == root)
		return root;
	ds[root] = FindSup(ds[root]);
	return ds[root];
}

void Union(int root1, int root2)
{
	int x = FindSup(root1);
	int y = FindSup(root2);
	if (x == y)
		return;
	if (x> y)
		ds[y] = x;
	else
		ds[x] = y;
	/*else
	{
		ds[x] = y;
		ranks[y]++;
	}*/
}

int main()
{
	int N, M, cnt = 0;
	int x, y;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		ds[i] = i;
		//ranks[i] = 0;
	}	

	for (int i = 0; i < M; i++)
	{	
		scanf("%d %d", &x, &y);
		if (FindSup(x) != FindSup(y))
		{
			Union(x, y);
			cnt++;
		}	
	}
	cnt = N - 1 - cnt;
	if (cnt < 0)
		cnt = 0;
	printf("%d", cnt);
	 
	 return 0;
}