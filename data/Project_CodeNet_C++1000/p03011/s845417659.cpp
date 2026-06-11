#include <iostream>
#include<map>

using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int A[3];
    cin >> A[0] >> A[1] >> A[2];
    sort(A,A+3);
    fin(A[0]+A[1]);
    return 0;
}