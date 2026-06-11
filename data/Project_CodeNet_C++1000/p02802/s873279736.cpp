#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;

int main(void) {
    int N,M; cin >> N >> M;
    vector<int> Ans(N+10,0);
    int collect = 0, penalty = 0;
    for(int i=1; i<=M; i++) {
        int p; cin >> p;
        string S; cin >> S;
        if(Ans[p] != -1) {
            if(S == "WA") Ans[p]++;
            else if(S == "AC") {
            penalty += Ans[p];
            collect++;
            Ans[p] = -1;
            }
        }
    }
    cout << collect << " " << penalty << endl;
}