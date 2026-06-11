#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll A,B,N;
    cin >> N >> A >> B;
    ll ans = 0;
    if ((B-A)%2==0) {
        ans = (B-A)/2;
    }
    else {
        ans = A + ((B-A)-1)/2;
        ans = min(ans,(N-B+1)+(N-(A+N-B+1))/2);
    }
    cout << ans << endl;
}
