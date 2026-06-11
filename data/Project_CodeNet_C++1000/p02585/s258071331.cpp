#include<iostream>
#include<algorithm>
using namespace std;
const int NODE = 5005;
const long long INF = 1LL << 60;


int nNode, nMove;
int go[NODE];
int add[NODE];

void read() {
    cin >> nNode >> nMove;
    for (int i = 0; i < nNode; ++i) {
        cin >> go[i];
        --go[i];
    }
    for (int i = 0; i < nNode; ++i) {
        cin >> add[i];
    }
}


void work() {
    long long maxV = -INF;
    
    for (int init = 0; init < nNode; ++init) {
        long long sum = 0;
        bool visited[NODE] = {};
        
        int node = init;
        int cycleLen = 0;
        for (int i = 0; i < nMove; ++i, ++cycleLen) {
            if (visited[node]) {
                long long toCmp = sum * ((nMove / cycleLen) - 1);
                maxV = max(maxV, toCmp);
                
                for (int ii = 0; ii < nMove % cycleLen + cycleLen; ++ii) {
                    node = go[node];
                    toCmp += add[node];
                    maxV = max(maxV, toCmp);
                }
                goto _finish;
            }
            visited[node] = true;
            
            node = go[node];
            sum += add[node];
            maxV = max(maxV, sum);    
        }
    _finish:;
    }

    cout << maxV << endl;
}


int main() {
    read();
    work();
    return 0;
}
