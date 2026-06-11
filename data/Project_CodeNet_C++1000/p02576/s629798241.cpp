#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int N, X, T, a = 0, b;
    cin >> N >> X >> T;
   
    do {
        a = a + X;
        b++;
   } while (N > a);

    cout << T * b << endl;
}