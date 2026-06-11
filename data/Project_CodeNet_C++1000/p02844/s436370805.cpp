#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<int> pas;
    int cnt = 0;
    for (int i = 0; i < 1000; i++) {
        string tmp;
        if (i < 10) tmp = "00" + to_string(i);
        else if (i < 100) tmp = '0' + to_string(i);
        else tmp = to_string(i);

        int idx = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == tmp[idx]) idx++;
            if (idx == 3) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;
    // for (int i = 0; i < s.size()-2; i++) {
    //     for (int j = i + 1; j <=s.size()-1; j++) {
    //         for (int k = j + 1; k < s.size(); k++) {
    //             // cout << (s[i] - '0')*100 + (s[j] - '0')*10 + (s[j] - '0') << endl;
    //             pas.insert((s[i] - '0')*100 + (s[j] - '0')*10 + (s[k] - '0'));
    //         }
    //     }
    // }

    // cout << pas.size() << endl;

}