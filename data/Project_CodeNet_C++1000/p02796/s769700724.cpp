#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> bot(n), bot_arm(n);
    for (int i = 0; i < n; i++)
    {
        int x, l;
        cin >> x >> l;
        bot[i] = make_pair(x, l);

        int left = x - l, right = x + l;
        bot_arm[i] = make_pair(right, left);
    }

    sort(bot_arm.begin(), bot_arm.end());
    int ans = 0,arm_left = bot_arm[0].second - 10;
    for (int i = 0; i < n; i++)
    {
        if(arm_left <= bot_arm[i].second)
        {
            arm_left = bot_arm[i].first;
            ans ++;
        }
    }
    cout << ans << endl;
}