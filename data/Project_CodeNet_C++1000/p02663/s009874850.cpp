#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int H1, M1, H2, M2, K;
    cin >> H1 >> M1 >> H2 >> M2 >> K;
    int M_diff = M2 - M1;
    if (M_diff < 0)
    {
        --H2;
        M_diff += 60;
    }
    int H_diff = H2 - H1;
    if (H_diff < 0)
        H_diff += 24;

    cout << H_diff * 60 + M_diff - K << endl;
}