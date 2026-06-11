#include <iostream>
#include <vector>

void dfs(long long now, long long previous, std::vector<std::vector<long long> >& tree, std::vector<long long>& cost, std::vector<bool>& visit)
{
	visit.at(now) = true;
	if (previous >= 0)
		cost.at(now) += cost.at(previous);
	for (int i = 0; i < tree.at(now).size(); i++)
	{
		long long next = tree.at(now).at(i);
		if (visit.at(next) == false)
		{
			dfs(next, now, tree, cost, visit);
		}
	}
	
}


int main()
{
	long long n, q;
	std::cin >> n >> q;
	std::vector<std::vector<long long> > tree(n);
	std::vector<long long> counter(n , 0);
	for (int i = 0; i < n - 1; i++)
	{
		long long a, b;
		std::cin >> a >> b;
		a--;
		b--;
		tree.at(a).push_back(b);
		tree.at(b).push_back(a);
	}
	std::vector<long long> cost(n, 0);
	std::vector<bool> visit(n, false);
	for (int i = 0; i < q; i++)
	{
		long long a, b;
		std::cin >> a >> b;
		a--;
		cost.at(a) += b;
	}

	dfs(0, -1, tree, cost, visit);
	for (int i = 0; i < n; i++)
	{
		std::cout << cost.at(i) << ' ';	
	}
	std::cout << '\n';
}