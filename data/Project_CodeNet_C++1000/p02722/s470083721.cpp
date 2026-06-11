#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1000000007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

vector<long long> divisor(long long n) {
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

bool judge(long long K, long long N){
    if(N%K==0) return judge(K, N/K);
    else return N%K==1;
}

int main(){
    long long N;
    cin >> N;
    auto div0 = divisor(N);
    auto div1 = divisor(N-1);
    long long ans = 0;
    for(auto x : div0){
        if(x == 1) continue;
        ans += judge(x, N);
    }
    ans += div1.size() - 1;
    cout << ans << endl;
    return 0;
}

