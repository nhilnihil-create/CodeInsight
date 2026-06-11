#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    size_t len = S.length();

    int amari[2019] = {};
    amari[0]++;
    uint64_t Ti(0),t(1);
    for (size_t i = 0; i < len; ++i)
    {
        int a = S[i]-'0';
        Ti = (a * t + Ti) % 2019;
        t = t * 10 % 2019;
        amari[Ti]++;
    }
    uint64_t ans(0);
    for (size_t i = 0; i < 2019; ++i)
        ans += (uint64_t)amari[i]*(amari[i]-1)*0.5;
    cout << ans << endl;

	return 0;
}

