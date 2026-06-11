#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    vector<int> p;
    int n, contador = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        p.push_back(x);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (p[i] > p[i - 1] && p[i] < p[i + 1])
        {
            contador++;
        }
        else if (p[i] < p[i - 1] && p[i] > p[i + 1])
        {
            contador++;
        }
    }
    cout << contador << endl;
    return 0;
}