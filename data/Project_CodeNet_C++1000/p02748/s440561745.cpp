#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int A, B, M;
    vector<int> as, bs, xs, ys, cs;
    cin >> A >> B >> M;
    copy_n(istream_iterator<int>(cin), A, back_inserter(as));
    copy_n(istream_iterator<int>(cin), B, back_inserter(bs));
    for (int i = 0; i < M; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        xs.push_back(x);
        ys.push_back(y);
        cs.push_back(c);
    }

    vector<int> plices;
    for (int i = 0; i < M; ++i)
    {
        // 割引セットの値段
        plices.push_back(as[xs[i] - 1] + bs[ys[i] - 1] - cs[i]);
    }

    auto min_a = *min_element(as.begin(), as.end());
    auto min_b = *min_element(bs.begin(), bs.end());

    // 割引を使わない最も安い組み合わせ
    plices.push_back(min_a + min_b);

    cout << *min_element(plices.begin(), plices.end()) << endl;

    return 0;
}
