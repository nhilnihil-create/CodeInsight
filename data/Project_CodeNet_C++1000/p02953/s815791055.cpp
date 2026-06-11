#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<int> H;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        H.push_back(temp);
    }

    for (int i = N - 2; i > 0; --i)
    {
        if (H[i] - 1 == H[i + 1])
        {
            H[i] -= 1;
        }
        else if (H[i] > H[i + 1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
