#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

set <string> s;

int main()
{
    int n;

    cin >> n;
    rep(i, n) {
        string s1;
        cin >> s1;
        s.insert(s1);
    }

    std::cout << s.size() << endl;

    return(0);
}
