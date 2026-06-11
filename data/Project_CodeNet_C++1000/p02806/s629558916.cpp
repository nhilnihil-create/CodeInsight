#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    pair<string, int> playlist[N];
    string title;
    int time;
    for (int i = 0; i < N; i++) {
        cin >> title >> time;
        playlist[i] = pair<string, int>(title, time);
    }
    string X;
    cin >> X;
    int total_time = 0;
    int sleep_start = 0;

    for (int i = 0; i < N; i++) {
        total_time += playlist[i].second;
        if (X == playlist[i].first ) {
            sleep_start = total_time;
        }
    }

    cout << total_time - sleep_start << "\n";

    return 0;
}
