#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    ll n;
    cin >> n;
    string res = "";

    while(n > 0){
        if (n % 26 == 0){
            res += 'z';
            n /= 26;
            n -= 1;
        }
        else{
            res += (n % 26 - 1) + 'a';
            n /= 26;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}