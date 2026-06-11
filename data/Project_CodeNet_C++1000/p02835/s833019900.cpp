#include <iostream>
#include<map>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int A;
    int ans = 0;
    cin >> A;
    ans += A;
    cin >> A;
    ans += A;
    cin >> A;
    ans += A;

    fin((ans >= 22)?"bust":"win");
    return 0;
}