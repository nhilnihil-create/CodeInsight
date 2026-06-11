#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ans = 0;
    for(int i=1; i<s.size(); i++){
        if(s.at(i-1)==s.at(i)) ans++;
    }

    ans = min(ans+2*k, n-1);
    cout << ans << endl;
    return 0;
}
