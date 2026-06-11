#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int ceil_ = ceil(N / 1.08);
    if (floor((ceil_ - 1) * 1.08) == N)
    {
        cout << ceil_ - 1 << endl;
    }
    else if (floor(ceil_ * 1.08) == N)
    {
        cout << ceil_ << endl;
    }
    else if (floor((ceil_ + 1) * 1.08) == N)
    {
        cout << ceil_ + 1 << endl;
    }
    else
    {
        cout << ":(" << endl;
    }
}
