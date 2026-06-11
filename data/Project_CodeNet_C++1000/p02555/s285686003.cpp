/**So..a**/
#include<bits/stdc++.h>
//#include <chrono>
// Success after trying 5 hour 11 minute :(


using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define PB(x, v) x.push_back(v);
#define M_P(a, b) make_pair(a, b)
#define pll pair<ll, ll>
#define ll long long
#define mll map<ll, ll>
#define vl vector<ll>
#define fa(x, v) for(auto x: v)
#define fr(i, a, b) for(ll i= a;i <=b; i++)
#define TEST  int test; cin >> test; while(test--)
#define FTEST int TesT; cin >> TesT; for(int test = 1; test<=TesT; test++)

#define B_ begin()
#define E_ end()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define NL_ "\n"
#define F first
#define S second
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second

#define MOD 1000000007
#define  ull unsigned long long

ll cnt[2000+10];
bool ch[2000+10];
ll n;
ll make(ll n)
{
    if(n<3) return 0;

    ll sum = 0;
    if(ch[n]) return cnt[n];
        for(ll i = 3; i+3<=n; i++)
          sum+= make(n-i), sum%=MOD;
     ch[n] = 1;
     cnt[n] += sum;
     cnt[n]%=MOD;
     return cnt[n];
}
int main()
{
    memset(ch, 0, sizeof(ch));
    scanf("%lld", &n);
    cnt[1] = cnt[2] = 0;
    fr(i, 3 , n) cnt[i] = 1;
    make(n);
    printf("%lld", cnt[n]);

    return 0;
}
