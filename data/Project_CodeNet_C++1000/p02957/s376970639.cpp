#include <iostream>
#include<map>
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)

using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int A,B;
    cin >> A >> B;
    if((A+B)%2) fin("IMPOSSIBLE");
    else fin((A+B)/2);
    return 0;
}