#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    long step;
    cin >> N;
    vector<int> h(N);
    step = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> h.at(i);
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (h.at(i) > h.at(i + 1))
        {
            step += h.at(i) - h.at(i + 1);
            h.at(i + 1) = h.at(i);
        }
    }
    cout << step << endl;
    return (0);
}
