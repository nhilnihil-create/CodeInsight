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
    int N, H, Max;
    cin >> N >> Max;
    string ans = "Yes";

    for (int i = 1; i < N; i++) {
        cin >> H;
        if (H  < Max -1) {
            ans = "No";
            break;
        }
        else {
            Max = max(Max, H);
        }
    }

    cout << ans;

    return 0;

}

