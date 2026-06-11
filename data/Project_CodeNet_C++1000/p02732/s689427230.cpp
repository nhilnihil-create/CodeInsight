#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    long long count[200001] = {0};
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        count[A[i]]++;
    }

    long long totalCount = 0;
    for (int i = 1; i < 200001; i++) {
        if (count[i] > 1) {
            totalCount += (count[i] * (count[i] - 1)) / 2;
        }
    }

    for (int i = 0; i < N; i++) {
        long long ans = totalCount;
        if (count[A[i]] > 1) {
            ans -= ((count[A[i]] * (count[A[i]] - 1)) / 2)
                    - (((count[A[i]] - 1) * (count[A[i]] - 2)) / 2);
        }
        cout << ans << endl;
    }
    return 0;
}