#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef vector<int> V;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

ll powg(ll a, ll b){
    if(b==1) return a;
    else if(b%2==0){
        return powg(a*a,b/2);
    } else {
        return a*powg(a*a,(b-1)/2);
    }
}


int main() {
    ll n;
    cin >> n;
    if(n%2==1){
        cout << 0 << endl;
        return 0;
    }
    ll cnt=1;
    ll ans = 0;

    while (n/(2*powg(5,cnt))>=1)
    {
        ans += n/(2*powg(5,cnt));
        cnt++;
    }
    ans += n/(2*powg(5,cnt));;
    cout << ans << endl;
}