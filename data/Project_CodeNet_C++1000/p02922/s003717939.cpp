#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int arithmeticSequence(int a, int d, int n)
{
    return a + (n - 1) * d;
}
int main()
{
    int A, B;
    cin >> A >> B;
    for (int i = 1;; i++)
    {
        int res = arithmeticSequence(1, A - 1, i);
        if (res >= B)
        {
            cout << i - 1 << endl;
            break;
        }
    }
}