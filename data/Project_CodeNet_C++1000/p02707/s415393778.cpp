#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

set <string> s;

int main()
{
    int n,m;

    cin >> n;
    vector<int> buka(n+1);

    for (int i = 2;i <= n;++i) {
        cin >> m;
        ++buka[m];
    }

    for (int i = 1;i <= n;++i) {
        std::cout << buka[i] << endl;
    }

    return(0);
}
