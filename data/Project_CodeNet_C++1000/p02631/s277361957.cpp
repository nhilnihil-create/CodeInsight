#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n][40];
    int sum[40];
    memset(A, 0, sizeof(A));
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        int count = 0;
        while (a) {
            A[i][count] = a % 2;
            sum[count] += a % 2;
            a /= 2;
            count++;
        }
    }
    int ans[n][40];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 40; j++) {
            if (sum[j] % 2 == A[i][j]) ans[i][j] = 0;
            else ans[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        ll ret = 0;
        ll keta = 1;
        for (int j = 0; j < 40; j++) {
            ret += keta * ans[i][j];
            keta *= 2;
        }
        cout << ret << " ";
    }
    cout << endl;
    return 0;
}