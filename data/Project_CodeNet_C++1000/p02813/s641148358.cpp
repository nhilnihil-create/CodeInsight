#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;

    vector<int> p(n), q(n);

    for(int i = 0; i < n; ++i)
        cin >> p[i];
    for(int i = 0; i < n; ++i)
        cin >> q[i];

    vector<int> sorted = p;
    sort(sorted.begin(), sorted.end());

    ll p_cnt, q_cnt;
    ll cnt = 0;
    do {
        cnt++;
        if(sorted == p) p_cnt = cnt;
        if(sorted == q) q_cnt = cnt;
    } while(next_permutation(sorted.begin(), sorted.end()));

    cout << abs(p_cnt - q_cnt) << "\n";
    return 0;
}