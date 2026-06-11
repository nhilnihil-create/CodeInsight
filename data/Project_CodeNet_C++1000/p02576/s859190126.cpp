#include <iostream>

using namespace std;

int main(void) {
    int N, X, T;

    cin >> N >> X >> T;

    cout << T * ((N % X ? 1:0) + N / X) << endl;
    
    return 0;
}