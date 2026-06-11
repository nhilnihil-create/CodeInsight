#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
   string S;
   cin >> S;
   bool x = true;
   for (int i = 0; i < S.size(); i++)
    {
        if (i % 2 == 0 && S[i] == 'L')
            x = false;
        if (i % 2 == 1 && S[i] == 'R')
            x = false;
    }
    cout << (x ? "Yes" : "No");
}