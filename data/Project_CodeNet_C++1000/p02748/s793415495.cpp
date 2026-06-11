#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 9223372036854775807
#define MOD 1000000007

int main(void)
{
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> A(a), B(b);
    rep(i, a) cin >> A.at(i);
    rep(i, b) cin >> B.at(i);

    int minA = *min_element(A.begin(), A.end());
    int minB = *min_element(B.begin(), B.end());

    int min_cost = minA+minB;

    rep(i,m){
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;

        min_cost =min(min_cost,A.at(x) + B.at(y) - c);
    }
    cout << min_cost << endl;

    return 0;
}