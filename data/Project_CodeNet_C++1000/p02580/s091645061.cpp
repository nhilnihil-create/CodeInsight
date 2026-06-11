#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> rows(H, 0);
    vector<int> cols(W, 0);
    //vector<vector<bool> > exist(H, vector<bool>(W, false));
    set<pair<int, int> > st;
    for (int i=0; i<M; i++)
    {
        int h, w;
        cin >> h >> w;
        h--;
        w--;
        rows[h]++;
        cols[w]++;
        st.insert({h, w});
    }
    int max_row = *max_element(rows.begin(), rows.end());
    int max_col = *max_element(cols.begin(), cols.end());
    vector<int> hr(0);
    vector<int> hc(0);
    for (int i=0; i<H; i++)
    {
        if (rows[i]==max_row) hr.push_back(i);
    }
    for (int i=0; i<W; i++)
    {
        if (cols[i]==max_col) hc.push_back(i);
    }
    int ans = max_row + max_col -1;
    for (int i=0; i<hr.size(); i++)
    {
        for (int j=0; j<hc.size(); j++)
        {
            if (st.find({hr[i], hc[j]}) == st.end())
            {
                ans++;
                break;
            }
        }
        if (ans == max_row + max_col) break;
    }
    cout << ans << endl;
}