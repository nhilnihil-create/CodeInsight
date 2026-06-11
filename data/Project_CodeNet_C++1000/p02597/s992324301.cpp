#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    // int r = count(s.begin(), s.end(), "R")
    int ans = INT_MAX;
    int left = 0;                               //number of whites preceeding the divider
    int right = count(s.begin(), s.end(), 'R'); //number of reds following the divider
    for (int i = 0; i < n; i++)
    {
        ans = min(max(left, right), ans);
        left += s[i] == 'W';
        right -= s[i] == 'R';
    }
    cout << min(max(left, right), ans) << endl;
}