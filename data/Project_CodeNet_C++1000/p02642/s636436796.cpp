#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> vect(1000001, 0); //0なら未使用，1なら一回だけ出てきた，2なら二回以上出てきたもしくはより小さいAの要素の倍数

    for (int i = 0; i < N; i++) {
        if (vect[a[i]] == 0) {
            vect[a[i]] = 1;
            int j = 2;
            while (j * a[i] <= 1000000) {
                vect[j * a[i]] = 2;
                j++;
            }
        }
        else if (vect[a[i]] == 1) {
            vect[a[i]] = 2;
        }
    }

    int count = 0;
    for (int i = 0; i <= 1000000; i++) {
        if (vect[i] == 1) count++;
    }

    cout << count << endl;
}
