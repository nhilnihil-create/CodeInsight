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

int main(){
    int N,K;
    cin >> N >> K;
    ll R,S,P;
    cin >> R >> S >> P;
    string T;
    cin >> T;

    for(int i=K; i<N; i++){
        if(T[i-K] == T[i]){
            T[i] = 'a';
        }
    }

    ll ans = 0;
    for(auto c : T){
        switch(c){
        case 'r':
            ans += P;
            break;
        case 's':
            ans += R;
            break;
        case 'p':
            ans += S;
            break;
        }
    }
    cout << ans << endl;
}