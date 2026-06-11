#include <iostream>
#include<map>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int ans = 6;
    int minus;
    cin >> minus;
    ans -= minus;
    cin >> minus;
    ans -= minus;

    fin(ans);
    return 0;
}