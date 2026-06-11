#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int K,X;

    cin >> K >> X;
    for(int pos=X-K+1;pos<X+K;pos++) {
        cout << pos << " ";
    }
    cout << endl;
    return 0;
}
