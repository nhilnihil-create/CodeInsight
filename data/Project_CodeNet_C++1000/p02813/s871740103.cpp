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
const ll INF = (1LL << 60);
const double pi=acos(-1.0);
#define debug cout << "line : " << __LINE__ << " debug" << endl
/****** Template of some basic operations *****/
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/**************************************/
/******** User-defined Function *******/
int f(int n){
    if(n==0) return 1;
    return f(n)*f(n-1);
}
/**************************************/
/********** Main()  function **********/
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> p(n),q(n),r(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    rep(i,n) r[i] = i+1;


    int a=0,b=0;
    int j = 1;
    bool flag_a = true;
    bool flag_b = true;
    do{

        int cnt = 0;
        if(flag_a){
            rep(i,n){
                if(r[i]==p[i]) cnt++;
            }
            if(cnt==n) a = j;
        }


        cnt = 0;
        if(flag_b){
            rep(i,n){
                if(r[i]==q[i]) cnt++;
            }
            if(cnt==n) b = j;
        }

        j++;

    }while(next_permutation(all(r)));

    cout << abs(a-b) << endl;

}
/********  Main() Ends Here *************/
