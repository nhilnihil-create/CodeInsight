#include <bits/stdc++.h>
using namespace std;

long long modPow(long long a, long long n, long long waru) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) { res = res * a % waru; }
        a = a * a % waru;
        n >>= 1;
    }

    return res;
}

int main() {
    //
    long long waru = 998244353;
    long long num;
    long long kekka = 1;

    map<long long, long long> m;

    cin >> num;
    for (int i = 0; i < num; i++) {
        long long tmp;
        cin >> tmp;
        m[tmp]++;

        if (i == 0 && tmp != 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (m[0] != 1) {
        cout << 0 << endl;
        return 0;
    }

    long long cnt = 0;  //飛ばし対策(0，1，2，4ときたらエラー(4は物理的に不可能))
    long long pre = 1;
    for (auto itr : m) {
        if (itr.first == 0) continue;

        if (cnt == itr.first - 1) {
            long long tmp = itr.second;
            kekka *= modPow(pre, tmp, waru);
            kekka = kekka % waru;
            pre = tmp;
            cnt++;
        } else {
            // 0,1,2,3と順番に来なかったのでエラー
            cout << 0 << endl;
            return 0;
        }
    }

    cout << kekka << endl;
    //
}
