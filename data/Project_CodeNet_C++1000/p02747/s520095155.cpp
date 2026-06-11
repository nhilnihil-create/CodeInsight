#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    string S;
    cin >> S;

    bool A = S == "hi";
    bool B = S == "hihi";
    bool C = S == "hihihi";
    bool D = S == "hihihihi";
    bool E = S == "hihihihihi";
    if (A || B || C || D || E)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
