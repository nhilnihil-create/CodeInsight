#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num, k;

    cin >> num >> k;

    vector<long long> vec(num);
    vector<long long> vec2(num, 0);
    deque<long long> loop;
    for (int i = 0; i < num; i++) cin >> vec.at(i), vec.at(i)--;

    long long index = 0;
    while (true) {
        if (vec2.at(index) == 1) {
            while (loop.at(0) != index) {
                k--;
                loop.pop_front();

                if (k == 0) {
                    cout << loop[0] + 1 << endl;
                    return 0;
                }
            }
            break;
        }
        loop.push_back(index);
        vec2.at(index) = 1;
        index = vec.at(index);
    }

    cout << loop.at(k % loop.size()) + 1;

//
}
