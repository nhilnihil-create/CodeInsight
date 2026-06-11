#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int d1[n];
    int d2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d1[i] >> d2[i];
    }
    int numInRow = 0;
    for (int i = 0; i < n; i++)
    {
        if (d1[i] == d2[i])
        {
            numInRow++;
        }
        else
        {
            numInRow = 0;
        }
        if (numInRow == 3)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}