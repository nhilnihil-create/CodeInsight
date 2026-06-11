#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
        int H1, M1, H2, M2, K;
        cin >> H1 >> M1 >> H2 >> M2 >> K;
        int time = 60 * (H2 - H1) + M2 - M1 - K;

        cout << time << endl;
        return 0;
}
