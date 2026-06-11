#include <iostream>
using namespace std;

int boal[10];

bool dfs(int b,int c, int time)
{
	if(time >= 10)
		return true;
	
	if(boal[time] > b && dfs(boal[time], c, time + 1))
		return true;
	
	if(boal[time] > c && dfs(b, boal[time], time + 1))
		return true;
	
	return false;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	while(n > 0){
		for(int i = 0; i != 10; ++i)
			cin >> boal[i];
		
		if(dfs(0, 0, 0))
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
		
		n--;
	}
	return 0;
}