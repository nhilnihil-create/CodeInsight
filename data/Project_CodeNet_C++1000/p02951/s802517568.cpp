#include <iostream>
#include<map>

using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int A,B,C;
    cin >> A >> B >> C;
    if(A-B > C) fin(0);
    else fin(C-(A-B));
    return 0;
}