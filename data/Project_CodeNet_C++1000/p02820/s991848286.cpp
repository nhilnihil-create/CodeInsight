#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for (int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

int main()
{
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    vector<char> hand(N);
    int score = 0;
    rep(i, N)
    {
        if (i - K < 0)
        {
            if (T[i] == 's')
            {
                score += R;
                hand[i] = 'R';
            }
            else if (T[i] == 'p')
            {
                score += S;
                hand[i] = 'S';
            }
            else
            {
                score += P;
                hand[i] = 'P';
            }
        }
        else
        {
            if (T[i] == 's' && hand[i - K] != 'R')
            {
                score += R;
                hand[i] = 'R';
            }
            else if (T[i] == 'p' && hand[i - K] != 'S')
            {
                score += S;
                hand[i] = 'S';
            }
            else if (T[i] == 'r' && hand[i - K] != 'P')
            {
                score += P;
                hand[i] = 'P';
            }
            else
            {
                hand[i] = '0';
            }
        }
    }
    cout << score << endl;
    return 0;
}