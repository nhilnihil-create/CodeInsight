#include <bits/stdc++.h>
using namespace std;

int main() {
    long long L, R;
    long long Max, Min;
    long long tmp;
    long long kekka = 2020;
    cin >> L >> R;

    Max = max(L, R);
    Min = min(L, R);

    for (long long i = Min; i < Max; i++) {
        for (long long j = i + 1; j <= Max; j++) {
            tmp = (i * j) % 2019;

            if (kekka == tmp) {
                cout << kekka;
                return 0;
            }

            kekka = min(kekka, tmp);
        }
    }

    cout << kekka;
}