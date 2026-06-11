#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;


int main(int argc, char **argv)
{
	long double a, b, c; cin >> a >> b >> c;
	std::cout << ((a + 2*sqrt(a)*sqrt(b) + b < c)? "Yes" : "No")<< std::endl;
}