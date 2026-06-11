#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <bitset>
#include <map>
#include <math.h>
#include <utility>

using namespace std;

const double PI = acos(-1);

int main(){

    long long N, A, B;
    cin >> N >> A >> B;

    if ((B - A) % 2 == 0) {
        cout << (B - A) / 2 << endl;
    } else {
        cout << min(A + (B-A-1)/2, (N-B+1) + (B-A-1)/2) << endl;
    }

    return 0;
}