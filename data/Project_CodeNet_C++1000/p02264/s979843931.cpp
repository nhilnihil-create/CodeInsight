#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	queue<pair<string, int> > ple;
	int n,q;
	string name;
	int time;
	cin >> n>>q;
	for(int i = 0; i< n; i++)
	{
		cin >> name>>time;
		ple.push(make_pair(name,time));	
	}
	
	
	pair<string, int> u;
	int elapse  = 0, a;
	while(!ple.empty())
	{
		u = ple.front(); ple.pop();
		a = min(u.second, q);
		u.second -= a;
		elapse +=a;
		if(u.second>0)
			ple.push(u);
		else
			cout << u.first<<" "<<elapse<<endl;		
	}
}