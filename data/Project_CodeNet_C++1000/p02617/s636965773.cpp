#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int BUF = 200005;


int nNode, nEdge;
int edge[BUF][2];

void read() {
    cin >> nNode;
    nEdge = nNode - 1;
    for (int i = 0; i < nEdge; ++i) {
        cin >> edge[i][0] >> edge[i][1];
        --edge[i][0];
        --edge[i][1];
    }
}


void work() {
    long long ans = 0;
    for (int i = 0; i < nNode; ++i) {
        ans += 1LL * (i + 1) * (nNode - i);
    }

    for (int i = 0; i < nEdge; ++i) {
        if (edge[i][0] > edge[i][1]) {
            swap(edge[i][0], edge[i][1]);
        }
        ans -= 1LL * (edge[i][0] + 1) * (nNode - edge[i][1]);
    }
    
    cout << ans << endl;
}


int main() {
    read();
    work();
    return 0;
}
