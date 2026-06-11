#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
    long long int N, A, B, ans;
    cin >> N >> A >> B;
    
    if (A % 2 == B % 2) {
        ans = (B - A) / 2;
    }
    else {
        ans = min(A - 1, N - B) + (B - A + 1) / 2;
    }

    cout << ans;

    return 0;

}

