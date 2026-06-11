#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;

    int ans[n + 1] = {0}, l = sqrt(n);

    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= l; j++)
            for (int k = 1; k <= l; k++) {
                int temp = i * i + j * j + k * k + i * j + i * k + j * k;
                if (temp <= n)
                    ans[temp]++;
            }

    for (int i = 1; i <= n; i++) 
        cout << ans[i] << endl;
}