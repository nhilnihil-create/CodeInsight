#include <bits/stdc++.h>
using namespace std;

int main()
{
    //input
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> co(n);
    for (int i = 0; i < n; i++)
        cin >> co.at(i).first >> co.at(i).second;

    //judge
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        double k = sqrt(pow(co.at(i).first, 2) + pow(co.at(i).second, 2));
        if (k <= d)
            count++;
    }

    //output
    cout << count << endl;
    return 0;
}