#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int N, M;
    cin >> N >> M;

    int cnt_ac=0;
    vector<bool> check(N+1, false);
    vector<int> miss(N+1, 0);

    for(int i = 0; i < M; i++){
        int p;
        string S;
        cin >> p >> S;

        if(check.at(p)) continue;
        else if(S != "AC") miss.at(p)++;
        else {
            cnt_ac++;
            check.at(p) = true;
        }
    }

    int cnt_miss=0;

    for(int i = 0; i < N+1; i++){
        if(check.at(i)) cnt_miss += miss.at(i);
    }

    cout << cnt_ac << " " << cnt_miss << endl;
}
