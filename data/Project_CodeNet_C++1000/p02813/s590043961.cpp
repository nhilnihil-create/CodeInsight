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

bool cmp(vint A, vint B){
    REP(i,A.size()){
        if(A[i] != B[i]) return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    vint P(N),Q(N);
    cin >> P;
    cin >> Q;
    vint R;
    REP(i,N){
        R.pb(i+1);
    }
    vector<vint> coll;

    do{
        vint S;
        for(auto r:R)S.pb(r);
        coll.pb(S);
    }while(next_permutation(R.begin(),R.end()));

    sort(coll.begin(),coll.end());
    int pidx=0;
    int qidx=0;
    REP(i,coll.size()){
        if(cmp(coll[i],P))pidx=i;
        if(cmp(coll[i],Q))qidx=i;
    }
    cout << abs(pidx-qidx) << endl;
}