#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    ll left = 1;
    ll right = M + 1;
    ll _left = N - (M - 1);
    ll _right = N;
    while (1)
    {
        if (M % 2 == 1)
        {
            if (right - left == -1)
            {
                break;
            }
        }
        else
        {
            if (right - left == 0)
            {
                break;
            }
        }
        cout << left << " " << right << endl;
        left++;
        right--;
    }
    while (1)
    {
        if (M % 2 == 0)
        {
            if (_right - _left == -1)
            {
                break;
            }
        }
        else
        {
            if (_right - _left == 0)
            {
                break;
            }
        }
        cout << _left << " " << _right << endl;
        _left++;
        _right--;
    }
}