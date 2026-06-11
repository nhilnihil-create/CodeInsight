#include<iostream>
#include<vector>
using namespace std;
const int BUF = 100005;


int nVal;
int val[BUF];
int nEdge;
int edge[BUF][2];

void read() {
    cin >> nVal;
    for (int i = 0; i < nVal; ++i) cin >> val[i];

    cin >> nEdge;
    for (int i = 0; i < nEdge; ++i) {
        cin >> edge[i][0] >> edge[i][1];
    }
}


void work() {
    long long sum = 0;
    int id2cnt[BUF] = {};
    for (int i = 0; i < nVal; ++i) {
        ++id2cnt[val[i]];
        sum += val[i];
    }

    for (int loop = 0; loop < nEdge; ++loop) {
        int src = edge[loop][0];
        int dst = edge[loop][1];
        
        sum -= 1LL * src * id2cnt[src];
        sum += 1LL * dst * id2cnt[src];

        id2cnt[dst] += id2cnt[src];
        id2cnt[src] = 0;

        cout << sum << endl;
    }
}


int main() {
    read();
    work();
    return 0;
}
