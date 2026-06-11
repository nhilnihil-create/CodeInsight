#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {

    int N;
    cin >> N;
    int A[N];
    int B[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
        B[i] = A[i];
    }

    sort(B,B + N);
    int max_v = B[N-1];
    int sec_max_v = B[N-2];

    int max_idx = -1;
    int sec_max_idx = -1;

    for(int i = 0; i < N; i++ ){
        if(A[i] == max_v) max_idx = i;
        if(A[i] == sec_max_v) sec_max_idx = i;
    }

    for(int i = 0; i < N; i++){
        if(i != max_idx) cout << A[max_idx] << endl;
        else if(i == max_idx) cout << A[sec_max_idx] << endl;
    }

    return 0;
}