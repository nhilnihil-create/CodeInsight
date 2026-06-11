#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;


int main(void)
{
    int N;
    cin >> N;
    vector<long> P(N);
    vector<int> idx(N + 1, -1);
    long ans = 0;
    for (int i = 0; i < N; i++){
        cin >> P[i];
        idx[P[i]] = i + 1;
    }
    sort(P.begin(), P.end(), greater<long>());
    multiset<int> S;
    for (int i = 0; i < 2; i++)
    {
        S.insert(0);
        S.insert(N + 1);
    }
    for (int i = 0; i < N; i++)
    {
        S.insert(idx[P[i]]);
        multiset<int>::iterator itr =  S.find(idx[P[i]]);
        int l1, l2, r1, r2;
        itr--; l1 = *itr;
        itr--; l2 = *itr;
        for (int j = 0; j < 3; j++) itr++;
        r1 = *itr;
        itr++; r2 = *itr;
        ans += ((l1 - l2) * (r1 - idx[P[i]]) + (r2 - r1) * (idx[P[i]] - l1)) * P[i];
        //cout << ans  << endl;
    }
    cout << ans << endl;
    return 0;
}