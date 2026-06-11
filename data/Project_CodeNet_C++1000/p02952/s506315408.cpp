#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; // N > 0
    cin >> N;
    int counter = 0;
    for (int i = 1; i <= N; i++)
    {
        if (((int)(floor(log10(i)) + 1)) % 2 != 0)
        {
            counter++;
        }
    }

    cout << counter << endl;
    return 0;
}