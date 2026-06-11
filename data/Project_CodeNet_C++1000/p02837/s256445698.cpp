#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<pair<int,int>>> X(N,vector<pair<int,int>>(0));
    REP(i,N){
        cin >> A[i];
        X[i].assign(A[i],mp(0,0));
        REP(l,A[i]){
            cin >> X[i][l].F >> X[i][l].S;
            X[i][l].F--;
        }
    }
    int count = 0;
    REP(i,exp2(N)){
        bool ok = 1;
        REP(l,N){
            if((i & (1 << l)) != 0){
                REP(k,A[l]){
                    if(X[l][k].S == 0){
                        if((i & (1 << X[l][k].F)) != 0){
                            ok = 0;
                            break;
                        }
                    }else{
                        if((i & (1 << X[l][k].F)) == 0){
                            ok = 0;
                            break;
                        }
                    }
                }
            }
            if(!ok)break;
        }
        if(ok)chmax(count,__builtin_popcountll(i));
    }
    cout << count << "\n";
}