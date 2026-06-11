#include <bits/stdc++.h>
 
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	set <long long int> s;
	priority_queue <long long int,vector<long long int>,greater<long long int>> pque;
	int n;

	cin >> n;
	
	for(int i=1;i<=9;i++)
	{
		s.insert(i);
		pque.push(i);
	}

	while(!pque.empty())
	{
		if(s.size() > 110000)
		{
			break;
		}
		long long int val = pque.top();
		pque.pop();
		int x = val%10;
		if(x==0)
		{
			long long int next = 10*val + 1;
			s.insert(next);
			pque.push(next);
			next = 10*val;
			s.insert(next);
			pque.push(next);
		}
		else if(x==9)
		{
			long long int next = 10*val + 8;
			s.insert(next);
			pque.push(next);
			next = 10*val + 9;
			s.insert(next);
			pque.push(next);
		}
		else
		{
			long long int next = 10*val + (x-1);
			s.insert(next);
			pque.push(next);
			next = 10*val + (x+1);
			s.insert(next);
			pque.push(next);	
			next = 10*val + x;
			s.insert(next);
			pque.push(next);					
		}
	}

	vector <long long int> res;
	for(auto it : s)
	{
		res.push_back(it);
	}

	cout << res[n-1] << '\n';

	return 0;
}