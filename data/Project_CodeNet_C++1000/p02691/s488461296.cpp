#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A.at(i);

    map<int, int> cnt;
    ll ans = 0;
    for(int i=0; i<N; i++)
    {
        ans += cnt[i+1 - A[i]];
        cnt[i+1 + A[i]]++;
    }
    cout << ans << endl;

    return 0;
}