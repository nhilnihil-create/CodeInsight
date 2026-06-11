#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1000000007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

long long solve(long long n, long long x, long long m, long long k, vector<long long> &d){
    vector<long long> dd(d.size());
    for(int i=0; i<d.size(); i++) dd[i] = d[i] % m;

    long long a = 0;
    for(int i=0; i<k; i++){
        if(dd[i] != 0) continue;
        long long cnt = (n-1+(k-1-i))/k;
        a += cnt;
    }
    long long a1 = x;
    long long an = x;
    for(int i=0; i<k; i++){
        long long cnt = (n-1+(k-1-i))/k;
        an += cnt * dd[i];
    }
    long long b = an/m - a1/m;
    return n - 1 - a - b;
}

int main(){
    long long k, q;
    cin >> k >> q;
    vector<long long> d(k);
    REP(i, k) cin >> d[i];
    REP(i, q){
        long long n, x, m;
        cin >> n >> x >> m;
        cout << solve(n, x, m, k, d) << endl;
    }
    return 0;
}
