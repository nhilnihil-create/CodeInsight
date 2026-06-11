/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/05/01 10:44:45 by monoue           ###   ########.fr       */
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

using namespace std;

#define	int	long long
#define MOD 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

typedef long long			ll;
typedef vector<int>			VI;
typedef vector<vector<int>>	VVI;
typedef pair<int, int>		PII;

// TOP
void	Main()
{
	int	h, w;
	cin >> h >> w;
	VVI	V(h + 1, VI(w + 1));
	rep(i, w + 1)
		V.at(0).at(i) = 100;
	rep(i, h + 1)
		V.at(i).at(0) = 100;
	vector<string>	S(h + 1);
	rep(i, w + 1)
	S.at(0) += '.';
	rep(i, h)
	{
		cin >> S.at(i + 1);
		S.at(i + 1) = '.' + S.at(i + 1);
	}
	rep2(i, 1, h + 1)
	{
		rep2(j, 1, w + 1)
		{
			if (i == 1 && j == 1)
			{
				if (S.at(1).at(1) == '#')
					V.at(1).at(1) = 1;
				else
					V.at(1).at(1) = 0;
			}
			else if (S.at(i).at(j) == '.')
			{
				V.at(i).at(j) = min(V.at(i - 1).at(j), V.at(i).at(j - 1));
			}
			else
			{
				int	u, l;
				u = V.at(i - 1).at(j);
				if (S.at(i - 1).at(j) != '#')
					u++;
				l = V.at(i).at(j - 1);
				if (S.at(i).at(j - 1) != '#')
					l++;
				V.at(i).at(j) = min(u, l);
			}
		}
	}
	cout << V.back().back() << endl;
}
// END

int32_t	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
