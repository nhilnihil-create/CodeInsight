#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

void dfs(string head, int pos, int len)
{
    if (len == 0)
    {
        cout << head << endl;
        return;
    }

    for (int i = 0; i <= pos; i++)
    {
        char c = 'a' + (char)i;
        dfs(head + c, max(pos, i+1), len - 1);
    }
}

int main()
{
    int n; cin >> n;
    dfs("", 0, n);
}