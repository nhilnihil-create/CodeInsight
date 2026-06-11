#include <iostream>
#include<map>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int N,M; cin >> N >> M;
    if(N>M*2) fin(N-M*2);
    else fin(0);

    return 0;
}