#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;

vector<string> dfs(string s, ll depth, vector<char> symbol)
{
    vector<string> ret;
    if (depth == 0)
    {
        ret.push_back(s);
        return ret;
    }

    for (ll i = 0; i < symbol.size(); i++)
    {
        auto vec = dfs(s + symbol[i], depth - 1, symbol);
        for (auto &&e : vec)
        {
            ret.push_back(e);
        }
    }
    return ret;
}

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

enum Tenki
{
    Sunny,
    Cloudy,
    Rainy
};

int main()
{
    string s;
    cin >> s;

    Tenki tommorow;
    if (s == "Sunny")
    {
        tommorow = Cloudy;
    }
    else if (s == "Cloudy")
    {
        tommorow = Rainy;
    }
    else if (s == "Rainy")
    {
        tommorow = Sunny;
    }

    switch (tommorow)
    {
    case Cloudy:
        cout << "Cloudy" << endl;
        break;
    case Rainy:
        cout << "Rainy" << endl;
        break;
    case Sunny:
        cout << "Sunny" << endl;
        break;
    default:
        break;
    }
}