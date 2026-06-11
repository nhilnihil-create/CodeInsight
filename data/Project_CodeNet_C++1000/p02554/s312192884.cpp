#include <bits/stdc++.h>
 
using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define VPII vector<PII>
#define LD long double
#define INF 1000000000000
#define MOD 1000000007
#define MAXR 100000 // array max range

int mod(int a1,int a2){ a1%=a2; return ((a1 < 0) ? a1+a2 : a1); }
void mode(int& a1,int a2){ a1%=a2; a1=((a1 < 0) ? a1+a2 : a1); }

int powm(int x,int n,int m){
    int ret=1;
    R(i,n){
        ret*=x;
        //ret%=m;
        mode(ret,m);
    }
    return ret;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(11);
    cerr << fixed << setprecision(6);
    int n;
    cin >> n;
    cout << mod(powm(10,n,MOD) - 2*(powm(9,n,MOD)-powm(8,n,MOD)) - powm(8,n,MOD),MOD) << endl;
    return 0;
}
