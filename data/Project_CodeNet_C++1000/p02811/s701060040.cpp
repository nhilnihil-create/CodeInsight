#include <iostream>
#include<map>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int K,X;
    cin >> K >> X;
    if(K*500  >= X) fin("Yes");
    else fin("No");
    return 0;
}