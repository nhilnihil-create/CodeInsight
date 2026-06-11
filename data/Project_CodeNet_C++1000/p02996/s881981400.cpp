#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> tasks;

    int a, b;
    rep(i, 0, N)
    {
        cin >> a >> b;
        tasks.emplace_back(b, a);
    }

    sort(tasks.begin(), tasks.end());
    int sum = 0;
    bool ans = true;
    for (auto c : tasks)
    {
        sum += c.second;
        if (sum > c.first)
        {
            ans = false;
        }
    }
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
