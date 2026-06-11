#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    int m,d;
    cin >> m >> d;
    int ans = 0;
    if(m<4||d<21)ans = 0;
    else{
        for(int i=22;i<=d;i++){
            int num1 = i%10;
            int num10 = i/10;
            if(num1>=2&&num10>=2&&num1*num10<=m)ans++;
        }
    }
    COUT(ans);
    return 0;
}