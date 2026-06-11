#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int long long

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

typedef pair<int, int> pint;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front

#define MOD (1000 * 1000 * 1000 + 7)

int num_1(int n) {
    int a = 0;

    while (n) {
        if (n & 1) a++;
        n >>= 1;
    }

    return a;
}

void out(int i, int j) {
    cout << i << " " << j << endl;
}

signed main() {
    int N;
    cin >> N;

    if (num_1(N) == 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;

        out(1, 2);
        out(1, 3);
        out(2, 3+N);
        out(3, 2+N);
        out(2+N, 1+N);

        // out(2, 3+N);
        // out(3+N, 1+N);
        // out(1+N, 2+N);
        // out(2+N, 3+N);
        // cout << "1 2" << endl;
        // cout << "2 3" << endl;
        // cout << "3 " << (1+N) << endl;
        // cout << (1+N) << " " << (2+N) << endl;
        // cout << (2+N) << " " << (3+N) << endl;

        if (N % 2 == 1) {
            REPS(i, N/2-1) {
                int j = i * 2 + 2;
                out(1, j);
                out(1, j+1);
                out(j+1+N, j);
                out(j+N, j+1);
                // cout << 1 << " " << j << endl;
                // cout << 1 << " " << (j+1) << endl;
                // cout << (j+1+N) << " " << j << endl;
                // cout << (j+N) << " " << (j+1) << endl;
            }
        } else {
            REPS(i, N/2-3) {
                int j = i * 2 + 2;
                out(1, j);
                out(1, j+1);
                out(j+1+N, j);
                out(j+N, j+1);
            }

            int a = (N-2) ^ N;
            out(a, N-2);
            out(N-2, N);
            out(a, N+N);
            out(N+N, N-2+N);

            out(1, N-1);
            out(N+N, N-1+N);
        }
    }

    return 0;
}