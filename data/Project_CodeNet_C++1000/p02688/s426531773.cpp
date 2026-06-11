#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int N, K;
    cin >> N >> K;

    map<int, int> m;
    for (int i = 0; i < K; i++)
    {
        int d;
        cin >> d;

        for (int j = 0; j < d; j++)
        {
            int a;
            cin >> a;
            m[a]++;
        }
    }

    cout << N - m.size() << endl;
}