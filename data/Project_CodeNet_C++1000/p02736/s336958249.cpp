#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

class BinomialFactory2
{
    vi stock2;

    int k2(int n)
    {
        int count = 0;
        while (n % 2 == 0)
        {
            n /= 2;
            count++;
        }
        return count;
    }

public:
    explicit BinomialFactory2(int N)
    {
        stock2.resize(N + 1);
        for (int i = 1; i <= N; i++)
        {
            stock2[i] = stock2[i - 1] + k2(i);
        }
    }

    int bi(int n, int r) const
    {
        if (r == 0 || r == n) return 0;

        return stock2[n] - stock2[n - r] - stock2[r];
    }
};

int calc_parity(const BinomialFactory2 &bifac,const vi& a, int N)
{
    int parity = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] == 1 && bifac.bi(N - 1, i) == 0)
        {
            parity++;
        }
    }
    return parity % 2;
}

int f(vi& a, int N)
{
    BinomialFactory2 bifac(N);

    if (calc_parity(bifac, a, N) == 1)
    {
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        if (a[i] == 1)
        {
            return 0;
        }
        if (a[i] == 2)
        {
            a[i] = 1;
        }
    }

    if (calc_parity(bifac, a, N) == 1)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int main()
{
	int N;
	std::cin >> N;
	vi a(N);
	for (int i = 0; i < N; i++)
	{
		char c;
		std::cin >> c;
		a[i] = c - '1';
	}

	std::cout << f(a, N);
}
