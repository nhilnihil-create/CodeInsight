#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    if (s.back() == 's') s.push_back('e');
    cout << s << 's';
}