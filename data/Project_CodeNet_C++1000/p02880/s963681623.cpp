#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            a.push_back(i * j);
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (n == a[i])
        {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
}