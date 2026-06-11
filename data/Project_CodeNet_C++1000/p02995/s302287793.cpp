#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
int main()
{
    ll A,B,C,D,E;
    cin >> A >> B >> C >> D;
    E = C*D/__gcd(C,D);
    ll ans = B-A+1;
    if(A%C != 0){
        ans -= (B/C - A/C);
    }else{
        ans -= (B/C - A/C + 1);
    }
    if(A%D != 0){
        ans -= (B/D - A/D);
    }else{
        ans -= (B/D - A/D + 1);
    }
    if(A%E != 0){
        ans += (B/E - A/E);
    }else{
        ans += (B/E - A/E + 1);
    }
    cout << ans << endl;
}