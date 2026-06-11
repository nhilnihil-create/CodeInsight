#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N+1);
    vector<int> ans(N+1);
    rep(i, N){
        cin >> A[i+1];
    }
    for (int i = N; i >= 1; i--){
        int x = 0;
        for (int j = i; j <= N; j+=i){
            x += ans[j];
        }
        if (x%2 == A[i]){
            ans[i] = 0;
        } else {
            ans[i] = 1;
        }
    }
    queue<int> Q;
    int M = 0;
    rep(i, N){
        if(ans[i+1] == 1){
            Q.push(i+1);
            M++;
        }
    }

    cout << M << endl;
    while(!Q.empty()){
        cout << Q.front();
        Q.pop();
        if(Q.empty()){
            cout << endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}