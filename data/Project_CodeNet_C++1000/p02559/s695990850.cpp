#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a.at(i);
    }
    vector<pair<int, pair<int, int>>> Query(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> Query.at(i).first >> Query.at(i).second.first >> Query.at(i).second.second;
    }

    fenwick_tree<int64_t> fw(N);
    for (int i = 0; i < N; i++)
    {
        fw.add(i, a.at(i));
    }
    for (int i = 0; i < Q; i++)
    {
        if (Query.at(i).first == 0)
        {
            fw.add(Query.at(i).second.first, Query.at(i).second.second);
        }
        else
        {
            cout << fw.sum(Query.at(i).second.first, Query.at(i).second.second) << endl;
        }
    }

    return 0;
}
