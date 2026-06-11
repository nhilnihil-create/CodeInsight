#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
const int BUF = 1005;


int N, K;
int val[BUF];


void read() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> val[i];
}


void work() {
    sort(val, val + N);
    cout << accumulate(val, val + K, 0) << endl;
}


int main() {
    read();
    work();
    return 0;
}
