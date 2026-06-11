#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) {
        cin >> A[i];
    }

    sort(A.begin(),A.end());
    
    ll A_max = A.back();
    ll A_min = A.front();

    ll B[N-2][2];
    rep(i,N-2) {
        if (A[i+1]>0) {
            B[i][0] = A_min;
            B[i][1] = A[i+1];
            A_min -= A[i+1];
        }
        else {
            B[i][0] = A_max;
            B[i][1] = A[i+1];
            A_max -= A[i+1];
        }
    }
    cout << A_max - A_min << endl;
    rep(i,N-2) {
        cout << B[i][0] << " " << B[i][1] << endl;
    }

    cout << A_max << " " << A_min << endl;
}
