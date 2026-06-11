#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
    REP(i,9)
        REP(j,9)
            cout << i+1 << 'x' << j+1 << '=' << (i+1)*(j+1) << '\n';
}