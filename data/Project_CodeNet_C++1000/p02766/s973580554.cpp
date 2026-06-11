#include <iostream>

using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;

    int b = 1;
    int c = K;
    while ( N >= c ) {
        b ++;
        c *= K;
    }

    cout << b << endl;

    return 0;
}