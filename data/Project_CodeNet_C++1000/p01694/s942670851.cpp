#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(void) {

    int N;

    while (cin >> N, N) {
        int cnt = 0;
        pair<bool, bool> legs;
        legs.first = false;
        legs.second = false;
        bool onfloor = true;

        for (int i = 0; i < N; i++) {
            string f; cin >> f;

            if (f == "lu") {
                legs.first = true;
                if (onfloor && legs.second) {
                    cnt++;
                    onfloor = false;
                }
            }
            else if (f == "ru") {
                legs.second = true;
                if (onfloor && legs.first) {
                    cnt++;
                    onfloor = false;
                }
            }
            else if (f == "ld") {
                legs.first = false;
                if (!onfloor && !legs.second) {
                    cnt++;
                    onfloor = true;
                }
            }
            else if (f == "rd") {
                legs.second = false;
                if (!onfloor && !legs.first) {
                    cnt++;
                    onfloor = true;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}