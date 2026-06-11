#include<sstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iostream>
#include<iterator>
int main()
{
	long long int n, k, x, sum = 0;
	std :: cin >> n >> k;
	std :: vector<long long int> h;
	std :: vector<long long int> :: iterator it;
	for(long int i = 0 ; i < n; i++)
	{
		std :: cin >> x;
		h.push_back(x);
	}
	std :: sort(h.begin(), h.end(), [](long long int x, long long int y){return x < y;});
	it = h.end()-1;
	if(n <= k)
		std :: cout << "0";
	else
	{
		for(long long int i = 0; i < k; i++)
		{
			h.erase(it);
			it--;
		}
		for(long long int i = 0; i < h.size(); i++)
		{
			sum = sum + h[i];
		}
		std :: cout << sum;
	}
}