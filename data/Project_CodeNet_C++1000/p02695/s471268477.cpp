#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n, m, q;
    int a[50], b[50], c[50], d[50];
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> A(n, 1);
    int max_score = 0;

    while (true) {
        int score = 0;
        for (int i = 0; i < q; i++) {
            if (A[b[i] - 1] - A[a[i] - 1] == c[i])
                score += d[i];
        }
        max_score = max(max_score, score);

        // Generate next A
        int k = n - 1;
        while (A[k] == m && k >= 0) k--;
        if (k == -1) break;
        A[k]++;
        for (int i = k + 1; i < n; i++) A[i] = A[k];
    }
    cout << max_score << endl;
    return 0;
}