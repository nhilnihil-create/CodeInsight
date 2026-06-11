#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    string input;
    cin >> input;
    sort(input.begin(), input.end());
    if (input[0] == input[1] && input[2] == input[3]&&input[0]!=input[3])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
