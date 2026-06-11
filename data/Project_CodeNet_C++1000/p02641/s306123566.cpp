#include <iostream>

using namespace std;

int H[105];

int main()
{
    int X, N, x;

    cin >> X >> N;

    for(int i = 0 ; i < N; ++i)
    {
        cin >> x;
        H[x] = 1;
    }

    int left, right;

    left = right = X;

    while(true)
    {
        if(left >= 0 && !H[left])
        {
            cout << left;
            break;
        }
        if(right <= 101 && !H[right])
        {
            cout << right;
            break;
        }
        left--;
        right++;
    }

    return 0;
}
