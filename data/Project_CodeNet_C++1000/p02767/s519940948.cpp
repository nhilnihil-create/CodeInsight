#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include<stack>
#include<string>
#include<algorithm> 
#include <set>
#include<list>
#include <bit>
#include <bitset>
#include <cstdint>
#include <initializer_list>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> pos(N);
    int ans = 10000000;
    for (int i = 0; i < N; i++)cin >> pos[i];
    sort(pos.begin(), pos.end());
    int min_val = pos[0], max_val = pos[N - 1];
    int sum;
    for (int i = 0; i < max_val - min_val + 1; i++) {
        sum = 0;
        for (int j = 0; j < N; j++) {
            sum += (pos.at(j) - (min_val + i)) * (pos.at(j) - (min_val + i));
        }
        if (sum < ans)ans = sum;
    }
    cout << ans << endl;
    return 0;
}