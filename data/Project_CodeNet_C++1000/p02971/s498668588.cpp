#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    int top1 = 0;
    int top2 = 0;
    int top1num = -1;
    rep(i, N){
        cin >> A[i];
        if(A[i] >= top1){
            top2 = top1;
            top1 = A[i];
            top1num = i;
        } else if(A[i] >= top2){
            top2 = A[i];
        }
    }

    rep(i, N){
        if(i == top1num){
            cout << top2 << endl;
        } else {
            cout << top1 << endl;
        }
    }

    return 0;
}