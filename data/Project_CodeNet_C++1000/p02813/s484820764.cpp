#include <bits/stdc++.h>
using namespace std;

int	main()
{
    int N;
    cin >> N;
    vector<int> P_vec(N), Q_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> P_vec.at(i);
    for (int i = 0; i < N; ++i)
        cin >> Q_vec.at(i);
    vector<int> perm(N);
    for (int i = 0; i < N; ++i)
        perm.at(i) = i + 1;
    int a = -1, b = -1;
    int cnt = 0;
    do {
        ++cnt;
        if (equal(P_vec.begin(), P_vec.end(), perm.begin(), perm.end()))
            a = cnt;
        if (equal(Q_vec.begin(), Q_vec.end(), perm.begin(), perm.end()))
            b = cnt;
        if (a > 0 && b > 0)
            break;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << abs(a - b) << endl;
}
