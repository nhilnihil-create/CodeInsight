#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    if ((a == b || b == c || c == a) && !(a == b && b == c))
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}
