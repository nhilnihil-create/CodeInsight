#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    if(s == "Sunny")
        cout << "Cloudy";
    else if(s == "Rainy")
        cout << "Sunny";
    else if(s == "Cloudy")
        cout << "Rainy";
    cout << "\n";
    return 0;
}
