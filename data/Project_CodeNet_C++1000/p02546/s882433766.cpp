// ABC179A.cpp
//

#include <iostream>
#include <string>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using P = pair<int, int>;
int main()
{
    string s;
    cin >> s;
    int l = s.size();
    if (s[l - 1] == 's') {
        cout << s + "es" << endl;
        return 0;
    }
    else {
        cout << s + "s" << endl;
        return 0;
    }
}
