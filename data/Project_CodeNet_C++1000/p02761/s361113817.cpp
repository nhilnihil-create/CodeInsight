
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Main() {
    // input
    int N, M;
    cin >> N >> M;
    int num[N];
    // 左から桁数が多い
    for (int i = 0; i < N; i++) {
        num[i] = -1;
    }
    for (int i = 0; i < M; i++) {
        int s, c;
        cin >> s >> c;
        if (num[s-1] == -1) {
            num[s-1] = c;
        } else {
            if (num[s - 1] != c) {
                cout << "-1" << endl;
                return;
            }
        }
    }
    if (num[0] == 0 && N > 1) {
        cout << -1 << endl;
        return;
    }
    if (num[0] == -1) {
        if (N ==1) {
            num[0] = 0;
        } else {
            num[0] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        if (num[i] == -1) {
            num[i] = 0;
        }
    } 
    
    // output
    for (int i = 0; i < N; i++) {
        cout << num[i];
    }
    cout << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
