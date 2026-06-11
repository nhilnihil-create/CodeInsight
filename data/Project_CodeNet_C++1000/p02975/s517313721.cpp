#include<bits/stdc++.h>
using namespace std;
map<int, int> M;
int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		int x;
		scanf("%d", &x);
		M[x]++;
	}
	if(M[0] == N)
	{
		puts("Yes");
		return 0;
	}
	if(N%3 != 0)
	{
		puts("No");
		return 0;
	}
	int sum = 0;
	for(map<int, int>::iterator it = M.begin(); it != M.end(); it++)
	{
		//cout << (*it).first << " " << (*it).second << endl;
		if((*it).second % (N/3) != 0)
		{
			puts("No");
			return 0;
		}
		int tmp = (*it).second/(N/3);
		while(tmp--)
			sum ^= (*it).first;
	}
	if(sum == 0)
		puts("Yes");
	else
		puts("No");
	return 0;
}