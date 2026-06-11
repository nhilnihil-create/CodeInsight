#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long double ld;
typedef long long ll;
const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;

int n, m, q;
vector<int> a, b, c, d;
int ans = 0;

void dfs(vector<int> &A, int &res){
    if(A.size() == n + 1){
        int sum = 0;
        for(int i = 0; i < q; i++){
            if(A[b[i]] - A[a[i]] == c[i]) sum += d[i];
        }
        ans = max(ans, sum);
        return;
    }
    int x = A.back();
    for(int i = x; i <= m; i++){
        A.push_back(i);
        dfs(A, res);
        A.pop_back();
    }

}

int main() {
    cin >> n >> m >> q;
    a = b = c = d = vector<int>(q);
    for(int i = 0; i < q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    int res = 0;
    vector<int> A(1,1);
    dfs(A, res);
    cout << ans << endl;

    return 0;
}
