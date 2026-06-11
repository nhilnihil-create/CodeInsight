// https://atcoder.jp/contests/abc175/tasks/abc175_c
#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
#include <iterator> // std::back_inserter
#include <climits>
#include <sstream>

using namespace std;

typedef unsigned long ll;

ll n;

int main()
{
    cin >> n;
    cout << (1000-(n % 1000))%1000 << endl;
}
