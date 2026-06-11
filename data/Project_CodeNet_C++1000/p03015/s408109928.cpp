//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18) + 1;
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int n, m;
string s;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
    vector<vector<ll>>dp(s.size()+1,vector<ll>(2,0));
    dp[0][0]=1;//flag0でLと同じ
    for(int i=1;i<=s.size();i++){
        for(int j=0;j<2;j++){
            if(j==0){
                if(s[i-1]=='1'){
                    dp[i][j]+=dp[i-1][j]*2;//10or01
                }
                else{
                    dp[i][j] += dp[i - 1][j];//00
                }
                dp[i][j] %= MOD;
            }
            else{
                if (s[i - 1] == '1')
                {
                    dp[i][j] += dp[i - 1][j] * 3; //10or01or00
                    dp[i][j] += dp[i - 1][0];//00
                }
                else
                {
                    dp[i][j] += dp[i - 1][j] * 3; //10or01or00
                }
                dp[i][j]%=MOD;
            }
        }
    }
    cout << (dp[s.size()][0]+dp[s.size()][1])%MOD<< "\n";
}
