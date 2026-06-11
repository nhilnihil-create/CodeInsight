// https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long H, W;
    cin >> H >> W;

    long cnt_odd = (H + 1) / 2;
    long cnt_even = H - cnt_odd;
    long pos_in_odd = (W + 1) / 2;
    long pos_in_even = W - pos_in_odd;

    long ans;
    if (H > 1 & W > 1)
    {
        ans = cnt_odd * pos_in_odd + cnt_even * pos_in_even;
    }
    else
    {
        ans = 1;
    }

    cout << ans << endl;
    return 0;
}
