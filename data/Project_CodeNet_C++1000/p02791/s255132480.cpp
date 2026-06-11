#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int P[N];
    for (int i = 0; i < N; i++) cin >> P[i];

    int min = P[0];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (min >= P[i]) {
            ans++;
            min = P[i];
        }
    }
    cout << ans << endl;
    return 0;
}