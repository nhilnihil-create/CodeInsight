#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int i=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int i=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1'000'000'007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

int main(){
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    priority_queue<pair<long long, int>> pq;
    for(int i=0; i<N; i++)
        if(B[i]!=A[i])
            pq.emplace(B[i], i);

    pair<long long, int> prv = make_pair(-1, -1);
    long long ans = 0;
    while(!pq.empty()){
        auto z = pq.top(); pq.pop();
        if(z==prv) break;;
        prv = z;
        long long b = z.first;
        int i = z.second;
        long long a = B[(i+N-1)%N];
        long long c = B[(i+1)%N];
        int n = (b-max(A[i], a+c+1))/(a+c);
        ans += n;
        b -= (a+c)*n;
        B[i] = b;

        if(b==A[i]) continue;
        ans++;
        b -= (a+c);
        B[i] = b;
        if(b==A[i]) continue;
        pq.emplace(B[i], i);
    }
    if(!pq.empty()) cout << -1 << endl;
    else cout << ans << endl;


    return 0;
}