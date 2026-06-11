#include <bits/stdc++.h>
using namespace std;
using RGB = tuple<int, int, int>;

void update_map(const map<RGB, int64_t> &cnt_map,
        map<int, vector<RGB>> &r_map,
        map<int, vector<RGB>> &g_map,
        map<int, vector<RGB>> &b_map)
{
    int r, g, b;
    r_map.clear();
    g_map.clear();
    b_map.clear();
    for (auto pr : cnt_map) {
        tie(r, g, b) = pr.first;
        if (!r_map.count(r)) r_map[r] = vector<RGB>();
        if (!g_map.count(g)) g_map[g] = vector<RGB>();
        if (!b_map.count(b)) b_map[b] = vector<RGB>();
        r_map[r].push_back(pr.first);
        g_map[g].push_back(pr.first);
        b_map[b].push_back(pr.first);
    }
}

int	main()
{
    const static int64_t mod = 1000000007;
    int N;
    cin >> N;
    vector<int> A_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> A_vec.at(i);
    map<int, vector<RGB>> r_map, g_map, b_map;
    vector<map<RGB, int64_t>> cnt_map(N + 1);
    cnt_map[0][make_tuple(0, 0, 0)] = 1;
    update_map(cnt_map[0], r_map, g_map, b_map);
    int r, g, b;
    for (int i = 0; i < N; ++i) {
        int A = A_vec.at(i);
        if (r_map.count(A)) {
            for (auto preb : r_map.at(A)) {
                tie(r, g, b) = preb;
                RGB key = make_tuple(r + 1, g, b);
                if (cnt_map.at(i + 1).count(key)) {
                    cnt_map.at(i + 1)[key] += cnt_map.at(i).at(preb);
                    cnt_map.at(i + 1)[key] %= mod;
                } else
                    cnt_map.at(i + 1)[key] = cnt_map.at(i).at(preb);
            }
        }
        if (g_map.count(A)) {
            for (auto preb : g_map.at(A)) {
                tie(r, g, b) = preb;
                RGB key = make_tuple(r, g + 1, b);
                if (cnt_map.at(i + 1).count(key)) {
                    cnt_map.at(i + 1)[key] += cnt_map.at(i).at(preb);
                    cnt_map.at(i + 1)[key] %= mod;
                } else
                    cnt_map.at(i + 1)[key] = cnt_map.at(i).at(preb);
            }
        }
        if (b_map.count(A)) {
            for (auto preb : b_map.at(A)) {
                tie(r, g, b) = preb;
                RGB key = make_tuple(r, g, b + 1);
                if (cnt_map.at(i + 1).count(key)) {
                    cnt_map.at(i + 1)[key] += cnt_map.at(i).at(preb);
                    cnt_map.at(i + 1)[key] %= mod;
                } else
                    cnt_map.at(i + 1)[key] = cnt_map.at(i).at(preb);
            }
        }
        update_map(cnt_map[i + 1], r_map, g_map, b_map);
    }
    int64_t cnt = 0;
    for (auto pr : cnt_map.at(N)) {
        cnt += pr.second;
        cnt %= mod;
    }
    cout << cnt << endl;
}
    
