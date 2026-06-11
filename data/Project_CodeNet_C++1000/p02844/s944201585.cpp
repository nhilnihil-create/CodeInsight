#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define Dcout(a) cout << setprecision(20) << a << endl
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using ll = long long;
using PAIR = pair<int, int>;
using Graph = vector<vector<int>>;
const double pi=acos(-1.0);
#define debug cout << "line : " << __LINE__ << " debug" << endl
/****** Template of some basic operations *****/
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/**************************************/
/******** User-defined Function *******/






/**************************************/
/********** Main()  function **********/
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;

    rep(i,10)rep(j,10)rep(k,10){
        bool flag1=false, flag2=false, flag3=false;
        rep(l,n){
            if(flag1==false){
                if(s[l]-'0'==i){
                    flag1 = true;
                    continue;
                }else continue;
            }
            
            if(flag2==false){
                if(s[l]-'0'==j){
                    flag2 = true;
                    continue;
                }else continue;
            }
            
            if(flag3==false){
                if(s[l]-'0'==k){
                    flag3 = true;
                    break;
                }else continue;
            }
        }
        if(flag1&&flag2&&flag3) ans++;
    }

    cout << ans << endl;
}
/********  Main() Ends Here *************/
