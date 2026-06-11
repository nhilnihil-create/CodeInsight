#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;
    if (unique(begin(S), end(S)) == end(S)) {
        cout << "Good\n";
    } else {
        cout << "Bad\n";
    }
}
