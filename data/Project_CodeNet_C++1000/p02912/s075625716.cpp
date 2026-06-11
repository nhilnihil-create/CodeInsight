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
    multiset<int> A;
    rep(i,N) {
        int a;
        cin >> a;
        A.insert(a);
    }
    rep(i,M) {
        int a = *A.rbegin();
        //cout << a << endl;
        A.erase(A.find(a));
        a /= 2;
        A.insert(a);
    }

    //cout << A.size() << endl;
    ll ans = 0;
    for (auto a:A) {
        ll b = a;
        ans += b;
    }
    cout << ans << endl;
}
