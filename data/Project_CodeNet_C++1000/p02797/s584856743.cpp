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

int main()
{
    ll N,K,S;
    cin >> N >> K >> S;
    if(N == K){
        REP(i,N){
            cout << S << " ";
        }
        cout << endl;
        return 0;
    }
    ll A = S/2;
    ll B = S-A;
    ll C;
    if(S == 1){
        A = 1;
        B = 1;
        K--;
    }
    if(S == 1e9){
        C = 1e9-1;
    }else{
        C = 1e9;
    }
    REP(i,N){
        if(i < K+1){
            if(0 == i%2){
                cout << A << " ";
            }else{
                cout << B << " ";
            }
        }else{
            cout << C << " ";
        }
    }
    cout << endl;
}