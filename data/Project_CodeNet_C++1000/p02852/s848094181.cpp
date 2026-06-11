#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

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
    int N = in(),M = in();
    string S = in<string>();
    reverse(ALL(S));
    vector<int> answer(0);
    bool ok = 1;
    for(int i = 0;i < N;){
        RREPS(l,M){
            if(i+l > N)continue;
            if(S[i+l] == '0'){
                answer.pb(l);
                i += l;
                break;
            }
            if(l == 1){
                ok = 0;
            }
        }
        if(ok == 0)break;
    }
    reverse(ALL(answer));
    if(ok){
        REP(i,answer.size())cout << answer[i] << "\n";
    }else{
        cout << -1 << "\n";
    }
}