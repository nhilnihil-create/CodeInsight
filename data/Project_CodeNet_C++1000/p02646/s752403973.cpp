#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[]) {

        long long int A, B, D1, D2;
        unsigned long long V, W, T;
        cin >> A >> V >> B >> W >> T;
        D1 = abs(A-B);
        D2 = (V-W)*T;
        puts(D1<=D2 ? "YES" : "NO");
        return 0;
}
