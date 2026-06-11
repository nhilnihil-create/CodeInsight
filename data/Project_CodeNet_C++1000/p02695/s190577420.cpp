#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main () {
    int n, m, q; //10 10 50
    cin >> n >> m >> q;
    int a[q], b[q], c[q], d[q];
    for(int i = 0; i < q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    ll max = 0;
    for (int i1 = 1; i1 <= m; i1++) {
        for (int i2 = i1; i2 <= m; i2++) {
            for (int i3 = i2; i3 <= m; i3++) {
                for (int i4 = i3; i4 <= m; i4++) {
                    for (int i5 = i4; i5 <= m; i5++) {
                        for (int i6 = i5; i6 <= m; i6++) {
                            for (int i7 = i6; i7 <= m; i7++) {
                                for (int i8 = i7; i8 <= m; i8++) {
                                    for (int i9 = i8; i9 <= m; i9++) {
                                        for (int i10 = i9; i10 <= m; i10++) {
                                            int i[11] = {0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
                                            ll now_max = 0;
                                            for (int j = 0; j < q; j++) {
                                                if (i[b[j]] - i[a[j]] == c[j]) {
                                                    now_max += d[j];
                                                }
                                            }
                                            if (max < now_max) {
                                                    max = now_max;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}