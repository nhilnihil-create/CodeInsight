# include <iostream>
# include <math.h>

using namespace std;

int main()
{
    string S;
    string T;

    cin >> S;
    cin >> T;

    int changes = 0;

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] != T[i])
            changes++;
    }

    cout << changes;

    return 0;
}