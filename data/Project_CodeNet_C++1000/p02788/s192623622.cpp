#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, D, A;
    cin >> N >> D >> A;
    vector<pair<int, int>> XH(N, make_pair(0, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> XH.at(i).first >> XH.at(i).second;
    }

    sort(XH.begin(), XH.end());

    int64_t res = 0;
    int64_t acc = 0;
    queue<pair<int, int64_t>> q;
    for (int i = 0; i < N; i++)
    {
        int Xi = XH.at(i).first, Hi = XH.at(i).second;
        while (!q.empty() && q.front().first < Xi)
        {
            auto f = q.front();
            acc -= f.second;
            q.pop();
        }
        Hi -= acc;
        
        if (Hi > 0)
        {
            int64_t count = (Hi + A - 1) / A;
            res += count;

            int64_t damage = A * count;
            Hi -= damage;
            acc += damage;
            q.push(make_pair(Xi + 2 * D, damage));
        }
    }

    cout << res << endl;
}