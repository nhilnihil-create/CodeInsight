#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define pb push_back
#define ALL(v) v.begin(),v.end()
const long long INF = 1LL << 60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

#if 0
string f(ll n)
{
    if(n == 0) return "";
    n--;
    //char t = 'a'+n%26;
    return f(n/26) + string(1, 'a'+n%26);
}
int main()
{
    ll N;
    cin >> N;
    cout << f(N) << endl;
    return 0;
}
#else
int main()
{
    ll N;
    cin >> N;
    string ans;
    while(N)
    {
        N--;
        ans += 'a'+N%26;
        N /= 26;
    }
    reverse(ALL(ans));
    cout << ans << endl;
    return 0;
}
#endif