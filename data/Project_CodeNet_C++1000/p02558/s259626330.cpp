#include<bits/stdc++.h>
#include <atcoder/dsu>
#define mp make_pair
#define fi first
#define se second
#define INF 10000000000000000LL
#define ll  long long 
const long long  inf =1e18+44;
const int MAX=3e5+9;
const ll MOD=1e9+7;
const int TOT_PRIMES=1e6+9;
const int MAX_A=71;
const int LN=20;
const double eps=1e-1;
using namespace std;
using namespace atcoder;
int dp[2000][2000];
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int q , n;
    cin>>q>>n;
    auto t = dsu(q+9);
    while(n--){
        int type , a, b;
        cin>>type>>a>>b;
        if ( type==0)
            t.merge(a, b);
        else
        {
            if(t.same(a,b))
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }

}
