#include <iostream>
#include<map>

using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int ans = 0;
    string S,SS;
    cin >> S >> SS;
    ans = (S[0] == SS[0]) +
          (S[1] == SS[1]) +
          (S[2] == SS[2]);
    fin(ans);
    return 0;
}