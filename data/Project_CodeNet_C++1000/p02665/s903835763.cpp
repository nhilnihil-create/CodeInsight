#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    vector<long long> vec(N + 1);
    for (long long i = 0; i < N + 1; ++i)
        cin >> vec[i];
    //可能か否かの判定
    vector<pair<long long, long long>> kanou(N + 1);
    kanou[N].first = vec[N];
    kanou[N].second = vec[N];
    for (long long i = N - 1; i >= 0; --i)
    {
        kanou[i].first = kanou[i + 1].first / 2 + kanou[i + 1].first % 2 + vec[i];
        kanou[i].second = kanou[i + 1].second + vec[i];
    }
    // for (auto i : kanou)
    //     cout << i.first << " " << i.second << "\n";
    //グラフが作成できない場合
    if (kanou[0].first > 1)
    {
        cout << "-1\n";
        return 0;
    }

    vector<long long> MAX(N + 1);
    MAX[0] = 1;
    long long result = MAX[0];
    for (long long i = 1; i < N + 1; ++i)
    {
        MAX[i] = min(kanou[i].second, 2 * (MAX[i - 1] - vec[i - 1]));
        result += MAX[i];
    }
    cout << result << "\n";
}
