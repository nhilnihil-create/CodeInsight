#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int N, M;
    string s;

    cin >> N;

    set<string> U;

    for (int i = 0; i < N; i++) {
        cin >> s;
        U.insert(s);
    }

    cin >> M;

    bool lock = true;

    for (int i = 0; i < M; i++) {
        cin >> s;
        if (U.find(s) == U.end()) {
            cout << "Unknown " << s << endl;
        } else if (lock) {
            cout << "Opened by " << s << endl;
            lock = false;
        } else {
            cout << "Closed by " << s << endl;
            lock = true;
        }
    }
    return 0;
}
