#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void dfs(int depth, vector<int>& s, int max_num, int n)
{
    if (depth == n)
    {
        for (auto i : s)
        {
            cout << static_cast<char>(i - 1 + 'a');
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= max_num + 1; i++)
        {
            s.push_back(i);
            dfs(depth + 1, s, max(max_num, i), n);
            s.pop_back();
        }
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> stack;
    dfs(0, stack, 0, n);
}
