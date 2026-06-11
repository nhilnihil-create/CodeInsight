#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //10^19 < 9223372036854775807
typedef unsigned long long ull; //10^20 < 18446744073709551615

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

#define MOD 1000000007


string ans = "";

string dog(ll N) {
    if (N > 0) {
        N -= 1;
        ans += ('a'+ N%26);
        N /= 26;
        return dog(N);
   }

    reverse(ALL(ans));
    return ans;
}

int main(void)
{
    ll N;
    cin >> N;

    cout << dog(N) << endl;

    return 0;
}
