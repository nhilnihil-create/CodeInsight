// ABC166B.cpp

#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int snk[110];
    for (int i = 1; i <= n; i++) {
        snk[i] = 0;
    }
    int dk = 0;
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            cin >> dk;
            snk[dk] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (snk[i] == 0)ans++;
    }
    cout << ans << endl;
}
