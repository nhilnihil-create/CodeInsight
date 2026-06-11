
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void Main() {
    // input
    u_int32_t N;
    cin >> N;

    map<string, u_int32_t> count_map;
    u_int32_t max_count = 0;
    for (u_int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if ((count_map.find(S)) == count_map.end()) {
            count_map[S] = 0;
        }
        count_map[S]++;
        max_count = max(max_count, count_map[S]);
    }

    // translate


    // output
    for (auto itr = count_map.begin(); itr != count_map.end(); itr++) {
        if (itr->second == max_count) {
            cout << itr->first << endl;
        }
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
