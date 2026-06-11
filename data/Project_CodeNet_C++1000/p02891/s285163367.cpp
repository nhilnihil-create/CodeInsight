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
    string S;
    ll K;
    cin >> S >> K;
    ll cnt = 0;
    ll sub = 0;
    bool same = false;
    if(S[0] == S[(int)S.size()-1]){
        ll a=1;
        ll b=1;
        REP(i,S.size()-1){
            if(S[i] == S[i+1]){
                a++;
            }else{
                break;
            }
        }
        for(int i=(int)S.size()-1; i>0; i--){
            if(S[i] == S[i-1]){
                b++;
            }else{
                break;
            }
        }
        if(a != (int)S.size()){
            sub = a/2+b/2-(a+b)/2;
            sub *= K-1;
        }else{
            same = true;
        }
    }
    REP(i,S.size()-1){
        if(S[i] == S[i+1]){
            S[i+1] = 'A';
            cnt++;
        }
    }
    if(same){
        cout << (((int)S.size()*K)/2) << endl;
    }else{
        cout << (cnt*K-sub) << endl;
    }
}