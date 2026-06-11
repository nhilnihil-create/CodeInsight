#include <iostream>
using namespace std;

int n,s;

int dfs(int num,int total,int de)
{
	int count = 0;

	if(de == n && total == s)
	{
		return 1;
	}
	if(de == n && total != s)
	{
		return 0;
	}

	for(int i=num; i<=9; i++)
	{
		count += dfs(i+1,total+i,de+1);
	}
	return count;
}

int main()
{

	while(cin >> n >> s, n || s)
	{
			dfs(0,0,0);
		cout << dfs(0,0,0) << endl;
	}

	return 0;
}