#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,K;
    string S;
    cin >> N >> K >> S;

    int a = 0;
    rep(i,N) {
        if (i==0) continue;
        if (S[i]!=S[i-1]) a++;
    }
    int ans = min(N-1, N-(a-K*2)-1);
    cout << ans << endl;
}
