/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/04/28 12:07:25 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

/* #include <boost/multi_array.hpp> */
/* #include <boost/optional.hpp> */
/* #include <boost/range/irange.hpp> */
/* #include <boost/range/algorithm.hpp> */
/* #include <boost/range/adaptors.hpp> */
/* #include <boost/multiprecision/cpp_int.hpp> */
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
/* using boost::multiprecision::cpp_int; */

#define MOD 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

// TOP
void	Main()
{
	ll	n;
	cin >> n;
	vector<ll>	V(n);
	unordered_map<ll, int>	M;
	rep(i, n)
	{
		int	x;
		cin >> x;

		V.at(i) = x;
		M[x]++;
	}
	if (M.size() == 1 && M[0])
	{
		cout << "Yes" << endl;
		return ;
	}
	if (M.size() == 2 && M[0] * 3 == n)
	{
		cout << "Yes" << endl;
		return ;
	}
	if (M.size() != 3 || n % 3)
	{
		cout << "No" << endl;
		return ;
	}
	int a;
	a = M.begin()->second;
	for (auto itr = M.begin(); itr != M.end(); itr++)
	{
		if (itr->second != a)
		{
			cout << "No" << endl;
			return;
		}
	}
	n = 0;
	for (auto itr = M.begin(); itr != M.end(); itr++)
		n ^= itr->first;
	if (n != 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}
// END

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
