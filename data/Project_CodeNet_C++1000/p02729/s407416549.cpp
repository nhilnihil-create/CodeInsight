#include <iostream>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int N,M;
    cin >> N >> M;
    fin(N*(N-1)/2+M*(M-1)/2);
    return 0;
}