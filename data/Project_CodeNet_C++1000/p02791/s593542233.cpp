#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int N;
    cin >> N;

    /*vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P.at(i);*/

    int MIN = 3e5, cnt=0;

    for(int i = 0; i < N; i++){
        int P;
        cin >> P;
        if(MIN > P) {
            MIN = P;
            cnt++;
        }
    }

    cout << cnt << endl;
}
