#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int N;
    cin >> N;

    double num = 0;
    int cnt = 0;
    int lp = N;
    while (lp > 0)
    {
        if (lp % 2 != 0) {
            cnt++;
            lp--;
        } else
        {
            lp--;
            continue;
        }
    }
    num = (double)cnt / N;

    cout << fixed << setprecision(10) << num << endl;
    
    return 0;
}
