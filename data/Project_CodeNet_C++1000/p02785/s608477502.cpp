
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void Main() {
    // input
    u_int32_t N, K;
    cin >> N >> K;
    vector<u_int32_t> monsters(N);

    for (u_int32_t i = 0; i < N; i++) {
        cin >> monsters[i];
    }

    u_int64_t count = 0;
    sort(monsters.begin(), monsters.end());
    
    // process
    while (!monsters.empty()) {
        if (K > 0) {
            K--;
            monsters.pop_back();
        } else {
            count += monsters.back();
            monsters.pop_back();
        }
    }


    // output
    cout << count << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
