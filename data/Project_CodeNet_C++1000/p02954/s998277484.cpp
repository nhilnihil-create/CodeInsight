#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define LL long long

void _131() {
    int n;
    cin >> n;
    int tmp_a, tmp_b;
    vector<pair<int, int> > data;
    for (int i = 0; i < n; ++i) {
        cin >> tmp_a >> tmp_b;
        data.push_back(make_pair(tmp_b, tmp_a));
    }

    sort(data.begin(), data.end());

    LL sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += data[i].second;
        // cout << sum << " " << data[i].first << endl;
        if (sum > data[i].first) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

void print_result(int length, int* result) {
    for (int i = 0; i < length; ++i) {
        cout << result[i];
        if (i != length - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

void _136() {
    string s;
    cin >> s;

    int result[100000] = {0};
    string::size_type pos;
    // LL times = (LL)pow((LL)10, 100);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'R') {
            pos = s.substr(i).find("RL");
            // cout << pos << endl;
            if (pos % 2 == 0) {
                result[i + pos]++;
            } else {
                result[i + pos + 1]++;
            }
        } else {
            // pos = s.substr(0, i).rfind("RL");
            pos = s.rfind("RL", i);
            // cout << pos << endl;
            if ((i - pos) % 2 == 0) {
                result[pos]++;
            } else {
                result[pos + 1]++;
            }
        }
        // print_result(s.length(), result);
    }

    print_result(s.length(), result);
}

void __136() {
    string s;
    cin >> s;

    int result[100000] = {0};

    string::size_type pos = 0;
    vector<int> rl_position;
    pos = s.find("RL", pos);
    while (pos != string::npos) {
        rl_position.push_back(pos);
        pos = s.find("RL", pos + 1);
    }

    int rl_index = 0;
    int next_rl_position = rl_position[rl_index];
    for (int i = 0; i < s.length(); ++i) {
        // cout << i << endl;
        if (s[i] == 'R') {
            if ((i != 0) &&(s[i - 1] == 'L')) {
                rl_index++;
                next_rl_position = rl_position[rl_index];
            }

            if ((next_rl_position - i) % 2 == 0) {
                result[next_rl_position]++;
            } else {
                result[next_rl_position + 1]++;
            }
        } else {
            if ((i - next_rl_position) % 2 ==0) {
                result[next_rl_position]++;
            } else {
                result[next_rl_position + 1]++;
            }
        }
    }

    print_result(s.length(), result);
}

int main()
{
    __136();
    return 0;
}

