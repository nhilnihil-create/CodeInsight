#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define DEBUG_ENABLED 0

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    // a[0] tells always true or false.
    // a0, a1, a2, ...
    // 1 1 0,   <- bit search it.

    vector<vector<pair<int, int>>> all_sayings;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        vector<pair<int, int>> tmp;
        for (int j = 0; j < a; j++)
        {
            int x, y;
            cin >> x >> y;
            pair<int, int> t = make_pair(x, y);
            tmp.push_back(t);
        }
        all_sayings.push_back(tmp);
    }

    // int max = numeric_limits<int>::min();
    int max = 0;

    for (int bit = 0; bit < (1 << N); ++bit)
    {
        long long mask = 0;

        if (DEBUG_ENABLED)
            cout << "---" << bit << endl;
        int is_truth_teller[N];
        for (int i = 0; i < N; ++i)
        {
            if (bit & (1 << i))
            {
                mask |= (1 << i);
            }

            is_truth_teller[i] = __builtin_popcount(bit & (1 << i));
            if (DEBUG_ENABLED)
                cout << "i: " << i << " is_truth_teller:" << is_truth_teller[i] << endl;
        }
        std::bitset<64> y(mask);
        if (DEBUG_ENABLED)
            cout << y << endl;

        // check
        bool is_acceptable = true;
        for (int i = 0; i < N && is_acceptable; ++i)
        {
            auto sayings = all_sayings.at(i);
            for (auto &p : sayings)
            {
                int who = p.first - 1;
                int s = p.second;
                // cout << "is_truth_teller[i]:" << is_truth_teller[i] << " who:" << who << " s:" << s << " is_truth_teller[who]:" << is_truth_teller[who] << endl;

                if (is_truth_teller[i])
                {
                    if (is_truth_teller[who] != s)
                    {
                        is_acceptable = false;
                        break;
                    }
                }
            }
        }
        if (is_acceptable)
        {
            int truth_tellers = __builtin_popcount(mask);
            if (max < truth_tellers)
            {
                max = truth_tellers;
            }
        }
    }

    cout << max << endl;
    return 0;
}
