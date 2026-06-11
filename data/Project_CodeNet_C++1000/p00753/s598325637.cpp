#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int sieve(int n)
{
	vector<int> vec, primes;
	for (int i = 2; i <= 2 * n; ++i)
		vec.push_back(i);

	int th = pow(2 * n, 0.5);
	while(vec.front() <= th){
		int top = vec.front();
		primes.push_back(top);
		auto it = remove_if(vec.begin(), vec.end(),
			[&](int& e) -> bool{
			if (e % top)
				return false;
			return true;
		});
		vec.erase(it, vec.end());
	}

	for (int& e:vec)
		primes.push_back(e);

	auto it = remove_if(primes.begin(), primes.end(),
		[&](int& e)-> bool{
		if (e <= n)
			return true;
		return false;
	});
	primes.erase(it, primes.end());

	return primes.size();
}

int main()
{
	int in;
	while ( cin >> in )
	{
		if (!in)
			break;
		int ret = sieve(in);
		cout << ret << endl;
	}

	return 0;
}