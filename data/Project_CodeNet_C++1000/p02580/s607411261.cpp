#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int H, W, M, i, j, h, w, h_max, w_max;
    cin >> H >> W >> M;
    vector<set<long long int>> h_set(H, set<long long int>());
    vector<set<long long int>> w_set(W, set<long long int>());
    vector<pair<long long int, long long int>> h_score(H);
    for (i = 0; i < H; i++)
    {
        h_score[i].first = 0;
        h_score[i].second = i;
    }
    vector<pair<long long int, long long int>> w_score(W);
    for (i = 0; i < W; i++)
    {
        w_score[i].first = 0;
        w_score[i].second = i;
    }
    for (i = 0; i < M; i++)
    {
        cin >> h;
        h -= 1;
        cin >> w;
        w -= 1;
        h_score[h].first += 1;
        w_score[w].first += 1;
        h_set[h].insert(w);
        w_set[w].insert(h);
    }
    sort(h_score.begin(), h_score.end(), greater<pair<long long int, long long int>>());
    sort(w_score.begin(), w_score.end(), greater<pair<long long int, long long int>>());
    h_max = h_score[0].first;
    w_max = w_score[0].first;
    i = 0;
    j = 0;
    long long int minus = 1;
    if (h_max == 0 && w_max == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        while (h_score[i].first == h_max && i < H)
        {
            j = 0;
            while (w_score[j].first == w_max && j < W)
            {
                if (h_set[h_score[i].second].find(w_score[j].second) == h_set[h_score[i].second].end() || h_set[h_score[i].second].empty())
                {
                    minus = 0;
                    goto OUT;
                }
                j++;
            }
            i++;
        }
    OUT:
        cout << h_max + w_max - minus << endl;
        return 0;
    }
}