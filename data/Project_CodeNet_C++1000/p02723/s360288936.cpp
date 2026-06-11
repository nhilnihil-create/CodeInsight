#include <iostream>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    string S;
    cin >> S;
    if(S[2] == S[3] && S[4] == S[5])fin("Yes");
    else fin("No");
    return 0;
}