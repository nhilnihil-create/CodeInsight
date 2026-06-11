#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    vector<int> v;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int dist = -1;
    for(int i = 1; i < N; i++) {
        dist = max(dist, v[i]-v[i-1]);
    }
    dist = max(dist, K-v[N-1]+v[0]);
    cout << K-dist << endl;
    return 0;
}