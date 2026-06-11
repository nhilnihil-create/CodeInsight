#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);



void dfs(ll i, int d, vector<ll> &A) {
    A.push_back(i);
    if (d==10) {
        return;
    }
    else {
        int tmp = i%10;
        for (int j = max(tmp-1,0); j<=min(9,tmp+1); j++) {
            dfs(i*10+j,d+1,A);
        }
    }
}

int main(){
    int N;
    cin >> N;

    vector<ll> A; 
    rep(i,9) {
        dfs(i+1,1,A);
    }
    sort(A.begin(),A.end());
    cout << A[N-1] << endl;
}