#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}}; ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}

/*!* [itertools] *!*/
/*+* イテレータの操作 *+*/
template<class I,class V=typename I::value_type>V sum_up(const I&l,const I&r){V v;for(I i=l;i!=r;i++)v=i==l?*i:v+*i;return v;}
template<class I,class T=iterator_traits<I>>I operator+(I it,int n){for(int i=0;i<n;i++)it++;return it;}
template<class I,class T=iterator_traits<I>>I operator-(I it,int n){for(int i=0;i<n;i++)it--;return it;}

int main() {
    i64 K, Q;
    cin >> K >> Q;
    vector<i64> D(K);
    for(i64 &d : D) cin >> d;
    for(int q = 0; q < Q; q++) {
        i64 n, x, m;
        cin >> n >> x >> m;
        i64 len = x % m;
        for(int j = 0; j < K; j++) {
            i64 d = D[j] % m;
            if(d == 0) d = m; // 距離0はmとみなす
            len += d * ((n - 1) / K);
            if(j < (n - 1) % K) {
                len += d;
            }
        }
        i64 ans = n - 1 - len / m;
        cout << ans << endl;
    }
    return 0;
}