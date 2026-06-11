#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> B(N-1);
    for(int i=0; i<N-1; i++) cin >> B.at(i);

    int ans = B[0] + B[N-2];
    for(int i=1; i<N-1; i++)
    {
        ans += min(B[i], B[i-1]);
    }
    cout << ans << endl;

    return 0;
}