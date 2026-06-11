/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/04/27 14:00:46 by monoue           ###   ########.fr       */
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

#define MOD 1e9+7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

// TOP
void	Main()
{
	string	s;
	ll		k;
	cin >> s >> k;

	ll	sum;
	sum = 0;
	ll	cnt;
	cnt = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s.at(i) == s.at(i - 1))
		{
			cnt++;
			if (cnt % 2)
				sum++;
		}
		else
			cnt = 0;
	}
	sum *= k;
	if (s.at(0) == s.back())
	{
		ll	na, nb;
		na = 1;
		nb = 1;

		rep(i, s.size() - 1)
		{
			if (s.at(i) == s.at(i + 1))
				na++;
			else
				break ;
		}
		if (na == s.size() && na % 2)
			sum += k / 2;
		else
		{
			for (int i = s.size() - 1; i > 0; i--)
			{
				if (s.at(i) == s.at(i - 1))
					nb++;
				else
					break;
			}
			if (na * nb % 2)
				sum += k - 1;
		}
	}
	cout << sum << endl;
}
// END

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
