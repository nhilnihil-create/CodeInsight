#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int N;
int m[16][16];
int m2[16][16];
int maxi = 0;

void f(int I, int ANS)
{
    if (I == N) {
        rep(i, N) {
            rep(j, N) {
                if (m[i][j] == 1 && m[j][j] == -2) {
                    goto lend;
                } else if (m[i][j] == 0 && m[j][j] == -1) {
                    goto lend;
                }
            }
        }
        if (ANS > maxi) maxi = ANS;
    lend:
        do { } while (0);
        
    } else {
        f(I+1, ANS);
        rep(i, 16) m[I][i] = -2;
        f(I+1, ANS - 1);
        rep(i, 16) m[I][i] = m2[I][i];
    }
}

int main()
{
    cin >> N;
    rep(i, N) {
        rep(j, N) {
            m[i][j] = -1;
            m2[i][j] = -1;
        }
    }
    rep(i, N) {
        int A;
        cin >> A;
        rep(j, A) {
            int x, y;
            cin >> x >> y;
            m[i][x - 1] = y;
            m2[i][x - 1] = y;
        }
    }
    f(0, N);

    cout << maxi << endl;
    return 0;
}
