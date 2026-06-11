#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int L, R, D;
    cin >> L >> R >> D;
    int cnt = 0;
    for (int it = L; it <= R; ++it) {
        if (it % D == 0) {
            cnt = it;
            break;
        }
    }
    if (cnt == 0) {
        cout << "0";
        return 0;
    }
    int res = (R - cnt + D) / D;
    cout << res;
    return 0;
}