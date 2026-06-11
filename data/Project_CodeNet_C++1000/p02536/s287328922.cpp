#include <iostream>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

int main()
{
    int N, M;
    int A, B;
    int ans = 0;

    cin >> N;
    cin >> M;

    dsu d(N);

    for (int i = 0; i < M; i++) {
        cin >> A;
        cin >> B;
        d.merge(A-1, B-1);
    }

    for (int i = 0; i < N-1; i++) {
        if (d.leader(i) != d.leader(i + 1)) {
            ans++;
            d.merge(i, i+1);
        }
    }
    cout << ans;

}
