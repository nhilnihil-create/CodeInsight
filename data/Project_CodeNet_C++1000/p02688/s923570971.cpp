#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int treatsArray[n] = {};
    for (auto ik = 0; ik < k; ik++) {
        int d;
        cin >> d;

        for (auto id = 0; id < d; id++) {
            int a;
            cin >> a;
            treatsArray[a-1]++;
        }
    }

    int tricks;
    for (auto treats: treatsArray) if (treats == 0) tricks++;
    cout << tricks;
}