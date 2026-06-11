#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> b(n);
    rep (i, n-1) cin >> b[i];

    int A = 0;
    rep (i, n) {
        if (i == 0)
            A += b[0];
        else if (i == n - 1) 
            A += b[n - 2];
        else 
            A += min(b[i - 1], b[i]);
    }

    cout << A << endl;

    return 0;
}