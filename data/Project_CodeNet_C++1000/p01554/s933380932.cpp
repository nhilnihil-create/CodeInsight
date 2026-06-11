#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void) {

    int N; cin >> N;
    set<string> U;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        U.insert(s);
    }

    int M; cin >> M;
    bool islocked = true;
    for (int i = 0; i < M; i++) {
        string T; cin >> T;

        if (U.find(T) != U.end()) {
            if (islocked) {
                cout << "Opened by " << T << endl;
            } else {
                cout << "Closed by " << T << endl;
            }
            islocked = !islocked;
        } else {
            cout << "Unknown " << T << endl;
        }
    }
    return 0;
}