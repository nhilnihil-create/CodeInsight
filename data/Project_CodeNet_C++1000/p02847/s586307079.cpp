#include <bits/stdc++.h>
using namespace std;

void solve(string S)
{
    map<string, int> m = {
        {"SUN", 7},
        {"MON", 6},
        {"TUE", 5},
        {"WED", 4},
        {"THU", 3},
        {"FRI", 2},
        {"SAT", 1}
    };
    cout << m.at(S) << endl;
}

int main()
{
    string S;
    cin >> S;
    solve(S);
    return 0;
}
