#include<iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int gcd(int p, int q) {
    if (p % q == 0)return q;
    return gcd(q, p % q);
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> num(n, -1);

    vector<int> s(m, 0), c(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> c[i];

        if (num[s[i] - 1] != -1 && num[s[i] - 1] != c[i]) {
            cout << -1;
            return 0;
        }
        num[s[i] - 1] = c[i];
    }


    switch (n) {
    case 1:
        if (num[0] == -1) num[0] = 0;
        cout << num[0];
        break;
    case 2:
        if (num[0] == 0) {
            cout << -1;
            return 0;
        }
        else if (num[0] == -1) {
            num[0] = 1;
        }

        if (num[1] == -1) num[1] = 0;
        cout << num[0] * 10 + num[1];
        break;
    case 3:
        if (num[0] == 0) {
            cout << -1;
            return 0;
        }
        else if (num[0] == -1) {
            num[0] = 1;
        }

        if (num[1] == -1) num[1] = 0;
        if (num[2] == -1) num[2] = 0;
        cout << num[0] * 100 + num[1] * 10 + num[2];
        break;
    }
    return 0;

}

