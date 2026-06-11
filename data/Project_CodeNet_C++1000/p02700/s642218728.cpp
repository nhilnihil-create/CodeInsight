#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ha, sa, hb, sb;
    cin >> ha >> sa >> hb >> sb;
    while (true)
    {
        hb -= sa;
        if (hb <= 0)
        {
            cout << "Yes";
            break;
        }
        ha -= sb;
        if (ha <= 0)
        {
            cout << "No";
            break;
        }
    }
}