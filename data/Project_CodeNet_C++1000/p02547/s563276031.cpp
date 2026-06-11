#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d[n][2];
    for (int i = 0; i < n; i++)
        cin >> d[i][0] >> d[i][1];

    int c = 0;
    int m = c;
    for (int i = 0; i < n; i++)
    {
        if (d[i][0] == d[i][1])
        {
            c++;
            if (c > m)
                m = c;
        }
        else
        {
            c = 0;
        }
    }

    string ans;
    if (m >= 3)
        ans = "Yes";
    else
        ans = "No";
    cout << ans << endl;
}