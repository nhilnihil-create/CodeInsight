#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    int counter = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i < 10)
        {
            counter++;
        }
        else if (i >= 100 && i <= 999)
        {
            counter++;
        }
        else if (i >= 10000 && i <= 99999)
        {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
