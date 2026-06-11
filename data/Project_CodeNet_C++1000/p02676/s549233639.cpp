#include <iostream>
#include <string>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using pii = pair<int, int>;
using pll = pair<LL, LL>;


int main()
{
    cin.sync_with_stdio(0);

    int K;
    string S;
    cin >> K >> S;
    int len = S.size();

    if (len <= K)
    {
        cout << S;
    }
    else
    {
        cout << S.substr(0, K) + "...";
    }
}