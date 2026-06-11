#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vi2 = vector<vector<int>>;
#define MP(a,b) make_pair((a),(b))
#define MT(...) make_tuple(__VA_ARGS__)
using ld = long double;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl;

#define DCOUT(x,n) cout << fixed << setprecision(n) << (x);

#define sz(x) (int)(x).size()
#define HOGE cout << "hoge" << endl;

template<typename T>inline istream& operator>>(istream&i,vector<T>&v)
{REP(j,sz(v))i>>v[j];return i;}

const int INF = 1e9;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> P(N);
    REP(i,N){
        int a,b;
        cin >> a >> b;
        P[i] = MP(b,a);
    }
    sort(P.begin(),P.end());
    bool isOK = true;
    ll time = 0;
    REP(i,N){
        time += P[i].second;
        if(time > P[i].first) isOK = false;
    }
    
    Yes(isOK);
}