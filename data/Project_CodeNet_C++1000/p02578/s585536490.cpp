#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    ll ret = 0;
    for(int i = 1; i < N; ++i){
        if(A[i-1] > A[i]){
            ret += A[i-1] - A[i];
            A[i] = A[i-1]; 
        }
    }
    cout << ret << '\n';
    return 0;
}