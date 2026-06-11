#include <bits/stdc++.h>
using namespace std;

void solve(string S)
{
    vector<string> w = {"Sunny", "Cloudy", "Rainy"};
    map<string, int> wtoi = {{"Sunny", 0}, {"Cloudy", 1}, {"Rainy", 2}};
    int i = wtoi.at(S);
    cout << w.at((i + 1) % 3) << endl;
}

int main()
{
    string S;
    cin >> S;
    solve(S);
    return 0;
}
