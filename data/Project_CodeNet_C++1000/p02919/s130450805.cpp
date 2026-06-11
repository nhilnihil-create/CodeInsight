#include <bits/stdc++.h>

using namespace std;


int main() {
    int N; cin >> N;
    vector<pair<int,int>> V;
    for(int i=1;i<=N;i++) {
        int tmp;
        cin >> tmp;
        V.push_back({tmp, i});
    }

    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());

    multiset<int> S;
    S.insert(0);
    S.insert(0);
    S.insert(N+1);
    S.insert(N+1);
    long long int ans = 0ll;
    for(int i=0;i<N;i++) {
        long long int num = V[i].first;
        long long int id = V[i].second;
        auto it = S.lower_bound(id);
        long long int r1 = *it++;
        long long int r2 = *it--;
        it--;
        long long int l1 = *it--;
        long long int l2 = *it;
        ans += num * max(0ll, id - l1) * (r2 - r1);
        ans += num * max(0ll, r1 - id) * (l1 - l2);
        S.insert(id);
    }
    cout << ans << endl;
    return 0;
}
