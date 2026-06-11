#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll n;
    cin >> n;

    string ans;

    while(n > 0){
        int x = n % 26;
        if(x == 0){
            ans.push_back('z');
        }else{
            ans.push_back('a'+x-1);
        }
        n = (n-1) / 26;
    }

    reverse(all(ans));

    cout << ans << "\n";

    return 0;
}