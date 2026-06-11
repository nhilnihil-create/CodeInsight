#include <bits/stdc++.h>
#define REP(i, n) REPI(i, 0, n)
#define REPI(i, a, b) for (int i = (int)(a) ; i < (int)(b) ; i++)

#define SZ(x) ((int)(x).size())


using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using namespace std;

int main()
{
    ll A, B;
    ull V, W, T;
    cin >> A >> V;
    cin >> B >> W;
    cin >> T;
    if (V > W && (abs(A-B) <= T * (V-W)))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}
