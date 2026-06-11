/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/05/01 09:21:44 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

/* #include <boost/multi_array.hpp> */
/* #include <boost/optional.hpp> */
/* #include <boost/range/irange.hpp> */
/* #include <boost/range/algorithm.hpp> */
/* #include <boost/range/adaptors.hpp> */
// #include <boost/multiprecision/cpp_int.hpp>
/* #include <boost/algorithm/string/classification.hpp> // is_any_of */
/* #include <boost/algorithm/string/split.hpp> */
/* #include <boost/algorithm/string/join.hpp> */
/* #include <boost/algorithm/string/replace.hpp> */
/* #include <boost/math/tools/minima.hpp> */
/* namespace adaptor = boost::adaptors; */
/* using boost::math::tools::brent_find_minima; */
/* using boost::irange; */
/* using boost::algorithm::join; */
/* using boost::algorithm::split; */
/* using boost::algorithm::replace_all; */
// using boost::multiprecision::cpp_int;

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define	int	long long
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

// TOP
void	Main()
{
	int	n, k;
	cin >> n >> k;

	VI	V(n);
	rep(i, n)
		cin >> V.at(i);
	int	sum;
	sum = 0;
	rrep(i, n - 1)
	{
		rrep(j, i - 1)
		{
			if (V.at(j) > V.at(i))
				sum++;
		}
	}
	sort(V.begin(), V.end());
	int	x;
	x = 0;
	rep(i, n - 1)
	{
		auto itr = upper_bound(V.begin(), V.end(), V.at(i));
		int a = V.end() - itr;
		x += a;
	}
	int f;
	f = k * (k - 1) / 2 % MOD;
	cout << ((f * x) % MOD + (sum * k) % MOD) % MOD << endl;
}
// END

int32_t	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
