#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    if (s[0] == 'S') cout << "Cloudy" << endl;
    if (s[0] == 'C') cout << "Rainy" << endl;
    if (s[0] == 'R') cout << "Sunny" << endl;
    return 0;
}