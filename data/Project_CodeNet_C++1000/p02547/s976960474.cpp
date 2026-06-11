#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
int a[110], b[110];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            ans++;
            if (ans == 3)
                return cout << "Yes", 0;
        }
        else
            ans = 0;
    }
    return cout << "No", 0;
    return 0;    
}