#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i=0; i< (int)(n); i++)
typedef long long ll;

// solution 2
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> ss(M), cc(M);
    rep(i, M) {
        cin >> ss[i] >> cc[i];
    }
    rep(i, pow(10, N)){
        string t = to_string(i);
        if (t.size() == N) {
            bool found = true;
            rep(j, M) {
                if (t[ss[j] - 1] != cc[j] + '0') {
                    found = false;
                    break;
                }
            }
            if (found) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;

}