#include <bits/stdc++.h>

using namespace std;

multiset <int> st, slimes;

int extract(int up_lim)
{
    auto it = st.lower_bound(up_lim);
    if (it == st.begin())
    {
        cout << "No\n";
        exit(0);
    }
    it--;
    st.erase(it);
    return *it;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    n = (1 << n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    slimes.insert(extract((int) 1e9 + 100));

    while (!st.empty())
    {
        vector <int> cur;
        for (auto &it : slimes)
        {
            cur.push_back(it);
        }

        for (auto &it : cur)
        {
            slimes.insert(extract(it));
        }
    }

    cout << "Yes\n";

}
