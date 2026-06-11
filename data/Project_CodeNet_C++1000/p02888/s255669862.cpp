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
    ll N;
    cin >> N;
    vll L(N);
    cin >> L;

    sort(L.begin(), L.end());

    ll ans = 0;
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            ll bc = L[i] + L[j];
            vll::iterator itr_bc = lower_bound(L.begin(), L.end(), bc);
            ans += itr_bc-L.begin()-j-1;
            
        }
    }
    cout << ans << endl;
}