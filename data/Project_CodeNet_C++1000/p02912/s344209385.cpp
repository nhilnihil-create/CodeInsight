#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,M;
    cin >> N >> M;
    priority_queue<int> A;
    rep(i,N) {
        int a;
        cin >> a;
        A.push(a);
    }

    rep(i,M) {
        int a = A.top();
        A.pop();
        a /= 2;
        A.push(a);
    }

    ll ans = 0;

    rep(i,N) {
        ll a = A.top();
        A.pop();
        ans += a;
    }
    cout << ans << endl;
}
