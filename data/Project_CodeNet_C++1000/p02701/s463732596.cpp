#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //10^19 < 9223372036854775807

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 
#define MOD 1000000007

int main(void)
{
    ll N;
    cin >> N;

    map<string,int> m;
    REP (i,N) {
        string s;
        cin >> s;
        m[s]++;
    }

    cout << SIZE(m) << endl;

    return 0;
}
