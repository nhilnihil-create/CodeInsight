#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> s;
    int a, b, c;
    cin >> a >> b >> c;

    s.insert(a);
    s.insert(b);
    s.insert(c);

    if (s.size()==2)        cout << "Yes";
    else                    cout << "No";

    return 0;
}
