#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

ll num = 0;
ll N = 0;

void dfs(vector<int> &A, int d) {
    if (A.size()==d) {
        num++;
        if (num==N) {
            rep(i,A.size()) {
                cout << A[i];
            }
            cout << endl;
        }
    }
    else {
        if (A.size()==0) {
            rep(j,9) {
                A.push_back(j+1);
                dfs(A,d);
                A.pop_back();
            }
        }
        else {
            int n = A.back();
            for (int j = max(0,n-1); j<=min(n+1,9) ; j++) {
                A.push_back(j);
                dfs(A,d);
                A.pop_back();
            }
        }
    }
}

int main(){
    cin >> N;
    num = 0;
    int cnt = 1;
    while(num<N) {
        vector<int> A;
        dfs(A,cnt);
        cnt++;
    }
}