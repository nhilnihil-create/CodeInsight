#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    int N, K, C;
    cin >> N >> K >> C;
    string s;
    cin >> s;

    vector<int> L(K), R(K);
    int cnt = 100000000; //休んだ日数
    int id = 0; //L(K)R(K)のidx

    for(int i = 0; i < N; i++) {
        if(s[i] == 'o') {
            if(cnt >= C) {
                if(id >= K) break;
                L[id] = i;
                id++;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        else {
            cnt++;
        }
    }

    id = K - 1;
    cnt = 100000000;
    for(int i = N - 1; i >= 0; i--) {
        if(s[i] == 'o') {
            if(cnt >= C) {
                if(id < 0) break;
                R[id] = i;
                id--;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        else {
            cnt++;
        }
    }

    for(int i = 0; i < K; i++) {
        if(L[i] == R[i]) cout << L[i] + 1 << endl;
    }

    /*
    for(int i = 0; i < K; i++) {
        cout << L[i] << " " << R[i] << endl;
    }
    */

    return 0;
}
