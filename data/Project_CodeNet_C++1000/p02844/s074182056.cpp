#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int res = 0;

    for (int i = 0; i <= 999; i++) {
        int fd = i % 10;
        int sd = (i / 10) % 10;
        int td = (i/ 100) % 10;
        int num[3] = {td, sd, fd};
        int d = 0;
        for (auto s : S) {
            int sd = s - '0';
            if (sd == num[d]) {
                if (d == 2) {
                    res++;
                    break;
                }
                d++;
            }
        }
    }

    printf("%d\n", res);



    return 0;
}
