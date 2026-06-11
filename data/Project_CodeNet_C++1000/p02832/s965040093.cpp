#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cnt = 1;

    int brk = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == cnt)
        {
            cnt++;
        }
        else
        {
            brk++;
        }
    }

    if (brk == n)
    {
        cout << -1 << endl;
    }

    else
    {
        cout << brk << endl;
    }

    return 0;
}