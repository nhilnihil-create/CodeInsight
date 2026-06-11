#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data.at(i);
    }
    sort(data.begin(),data.end());
    double ans = data.at(0);
    for (int i = 1; i < N; i++) {
        ans = (ans + data.at(i)) / 2;
    }
    cout << ans << endl;
}