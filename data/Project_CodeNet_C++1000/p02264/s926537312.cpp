#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Process
{
public:
	string name;
	int time;
};

void solve()
{
	int n, q;
	cin >> n >> q;
	queue<Process> process;
	for (int i = 0; i < n; ++i)
	{
		Process p;
		cin >> p.name >> p.time;
		process.push(p);
	}
	int sum = 0;
	while (!process.empty())
	{
		Process p = process.front();
		process.pop();
		if (p.time <= q)
		{
			sum += p.time;
			cout << p.name << " " << sum << endl;
		}
		else
		{
			sum += q;
			p.time -= q;
			process.push(p);
		}
	}
}

int main()
{
	solve();
	return(0);
}