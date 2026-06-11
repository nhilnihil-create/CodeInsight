#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, M;
    cin >> N  >> M;
    int A[M];
    rep(i, M) cin >> A[i];

    int sum=0;
    rep(i, M) sum+=A[i];

    int ans=N-sum;
    if(ans<0) ans=-1;
    cout << ans << endl;
    return 0;
}