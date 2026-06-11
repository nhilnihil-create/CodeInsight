#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> players(N, K);
    int x;
    for (int i = 0; i < Q; i++)
    {
        cin >> x;
        x--;
        players[x]++;
    }

    for (int i = 0; i < N; i++)
    {
        players[i] -= Q;
    }

    for (int i = 0; i < N; i++)
    {
        if (players[i] > 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return (0);
}