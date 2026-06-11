#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<vector<ll>> A;

signed main(){
    cin >> N;
    A.resize(N);
    for(int i=0;i<N;i++) {
        A[i].resize(N,0);
    }
    for(int i=0;pow(2,i)<N;i++) {
        for(int j=1;j<N;j++) {
            for(int l=1;j+l*pow(2,i)<=N;l++) {
                A[j-1][j+l*pow(2,i)-1] = i+1;
            }
        }
    }
    if(N%2==0) A[0][N-1] = 1;
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}