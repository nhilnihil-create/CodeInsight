#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

const int mxN = 1e5;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R') cnt++;
    }

    int ans = cnt;
    for (int i = 0; i < cnt; i++)
    {
        if (s[i] == 'R') ans--;
    }
    
    cout << ans << "\n";
}