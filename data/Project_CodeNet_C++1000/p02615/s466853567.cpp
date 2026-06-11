#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
const int BUF = 200005;


int N;
int val[BUF];

void read() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> val[i];
    }
}


void work() {
    sort(val, val + N);
    long long ans = 0 + val[N - 1];
    
    int idx = N - 2;
    for (int i = 2; i < N;) {
        ans += val[idx]; ++i;
        if (i < N) {
            ans += val[idx--];
            ++i;
        }
    }

    cout << ans << endl;
}


int main() {
    read();
    work();
    return 0;
}
