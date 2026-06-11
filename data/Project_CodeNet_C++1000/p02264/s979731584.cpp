#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;


int main()
{
	int q, n, i, time;
	string name;
	queue<pair<string, int> > Q;
    scanf("%d", &n);
    scanf("%d", &q);
    for(i=0;i<n;i++)
    {
    	cin >> name>> time;
    	Q.push(make_pair(name, time));
	}
	pair<string, int> u;
	i = 0;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		if(u.second>q)
		{
		    u.second -= q;
		    Q.push(u);
		    i += q;
		} 
		else 
		{
			i += u.second;
			cout << u.first << " ";
			//printf("%s ", u.first);
			printf("%d\n", i);
		}
	}
    //printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}