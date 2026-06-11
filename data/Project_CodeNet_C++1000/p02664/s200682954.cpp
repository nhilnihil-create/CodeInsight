#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()

int main() {

    string s;
    getline(cin, s);

    for (int i = 0; i < sz(s); i++) 
        if (s[i] == '?')
            s[i] = 'D';

    cout << s << endl;

    return 0;
}
