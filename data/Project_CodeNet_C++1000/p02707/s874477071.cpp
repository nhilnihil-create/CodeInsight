#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N; 
    cin >> N;
    int A[N]={0};
    for(int i=1; i<N; i++) cin >> A[i];
    
    int B[N]={0};
    rep(i, N) B[A[i]-1]++;

    rep(i, N) cout << B[i] << endl;
    return 0;
}