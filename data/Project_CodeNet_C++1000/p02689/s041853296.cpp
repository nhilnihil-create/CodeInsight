#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, M;
    cin >> N >> M;
    int H[N];
    rep(i, N) cin >> H[i];
    int A[M], B[M];
    rep(i, M) cin >> A[i] >> B[i];

    int nice[N];
    rep(i, N) nice[i]=1;
    rep(i, M){
        if(H[A[i]-1] > H[B[i]-1]) nice[B[i]-1]=0;
        else if(H[A[i]-1] < H[B[i]-1])nice[A[i]-1]=0;
        else if(H[A[i]-1] == H[B[i]-1]){
            nice[A[i]-1]=0;
            nice[B[i]-1]=0;
        }
    }

    int ans=0;
    rep(i, N) if(nice[i]==1) ans++;

    cout << ans << endl;
    return 0;
}