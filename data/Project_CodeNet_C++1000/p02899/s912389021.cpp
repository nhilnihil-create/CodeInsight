#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> serial(n);

    for (int i = 0; i < n; i++)
    {
        cin >> serial[i].first;
        serial[i].second = i + 1;
    }

    sort(serial.begin(), serial.end());

    for (auto students : serial)
        cout << students.second << " ";

    cout << endl;
    return 0;
}