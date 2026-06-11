#include <bits/stdc++.h>
#define Tayeb ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
using namespace std;
int main()
{
    Tayeb;
    int A,B;
    cin >> A >> B;
    if(A%2==B%2)
        cout << (A+B)/2 << "\n";
    else
        cout << "IMPOSSIBLE\n";

    return 0;

}
