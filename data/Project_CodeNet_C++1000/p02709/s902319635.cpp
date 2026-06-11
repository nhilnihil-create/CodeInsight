#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class I,class V=typename I::value_type>V sum_up(const I&l,const I&r){V v;for(I i=l;i!=r;i++)v=i==l?*i:v+*i;return v;}
template<class I,class T=iterator_traits<I>>I operator+(I it,int n){for(int i=0;i<n;i++)it++;return it;}
template<class I,class T=iterator_traits<I>>I operator-(I it,int n){for(int i=0;i<n;i++)it--;return it;}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}
void R_YESNO(bool p){cout<<(p?"YES":"NO")<<endl;}
void R_YesNo(bool p){cout<<(p?"Yes":"No")<<endl;}

using P = pair<i64, int>;

inline void max_assign(i64 &x, const i64 y) {
    x = max(x, y);
}

int main() {
    int N;
    cin >> N;
    vector<P> A(N);
    for(int i = 0; i < N; i++) {
        i64 a;
        cin >> a;
        A[i] = {a, i};
    }
    sort(REV_WHOLE(A));
    vector2d<i64> dp(N + 1, vector<i64>(N + 1, 0));
    for(int j = 0; j < N; j++) {
        i64 a;
        int i;
        tie(a, i) = A[j];
        // j = x + y
        for(int x = 0; x <= j; x++) {
            int y = j - x;
            max_assign(dp[x + 1][y], a * (i - x) + dp[x][y]);
            max_assign(dp[x][y + 1], a * (N - 1 - y - i) + dp[x][y]);
        }
    }
    i64 ans = 0;
    for(int x = 0; x <= N; x++) {
        int y = N - x;
        max_assign(ans, dp[x][y]);
    }
    cout << ans << endl;
    return 0;
}

