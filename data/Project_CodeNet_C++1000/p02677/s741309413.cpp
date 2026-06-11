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

int main(void)
{
    long double A,B,H,M;
    cin >> A >> B >> H >> M;

    long double rad = M_PI * 2 * ( H/12.0 + M/60.0/12.0 - M/60.0 );

    long double rsq = A*A + B*B - 2*A*B * cosl(rad);
    
    printf("%20.20Lf\n",sqrtl(rsq));

    return 0;
}
