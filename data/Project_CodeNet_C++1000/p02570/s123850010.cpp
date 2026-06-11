/*input
10000 1 1
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    int D, T, S;
    cin >> D >> T >> S;
    if (S*T >= D) puts("Yes");
    else puts("No");
}