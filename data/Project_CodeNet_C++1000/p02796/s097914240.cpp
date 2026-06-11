#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main (){
    ll N;
    cin >> N;
    ll X[N],L[N];
    vector<vector<ll>> A(N,vector<ll>(2));
    rep(i,0,N) {
        cin >> X[i] >> L[i];
        A[i][1] = X[i]-L[i];
        A[i][0] = X[i]+L[i];
    }

    sort(A.begin(),A.end());

    ll tmp = A[0][1];

    ll ans = 0;
    rep(i,0,N) {
        if (A[i][1]>=tmp) {
            ans++;
            tmp = A[i][0];
        }
    }

    cout << ans << endl;

}



