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
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

const double eps = 1e-16;

int main()
{
    ll a,b,c;
    cin >> a >> b >> c;
    c -= a+b;
    if((c <= 0)){
        cout << "No" << endl;
        return 0;
    }
    if(c*c > 4*a*b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}