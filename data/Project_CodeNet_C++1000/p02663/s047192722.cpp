#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h1, h2, m1, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int min = (60 - m1) + (h2 - h1 - 1) * 60 + m2;
    cout << min - k << endl;
}