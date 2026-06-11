#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int continueCount = 0;

    bool isYes = false;

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;

        if (a == b)
        {
            ++continueCount;

            if (continueCount == 3)
            {
                isYes = true;
            }
        }
        else
        {
            continueCount = 0;
        }
    }

    cout << (isYes ? "Yes" : "No") << endl;
}