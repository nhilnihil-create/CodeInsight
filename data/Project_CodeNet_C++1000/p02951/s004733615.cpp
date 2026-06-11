#include <bits/stdc++.h>
using namespace std;

#define max(a,b) (((a) < (b)) ? (b) : (a))
int main(void) {
    int64_t A,B,C;
    cin >> A >> B >>C;
    cout << max(0,C-(A-B)) << endl;
    return 0;
}
