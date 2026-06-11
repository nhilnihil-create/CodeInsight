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

int SierpinskiGasket(int n, int m) {
    int k = n - m;
    int n2 = 0, k2 = 0, m2 = 0;
    while(n) {
        n >>= 1;
        n2 += n;
    }
    while (k) {
        k >>= 1;
        k2 += k;
    }
    while (m) {
        m >>= 1;
        m2 += m;
    }
    return n2 > k2 + m2 ? 0 : 1;
}

int main() {
    int N;
    string S;
    cin >> N >> S;
    // 差分だけ考えるので-1してもよい
    for(char &c : S) c--;
    vector<int> A;
    
    // 2が答えの時だけは特別扱い
    // 2が答えのとき，1は含まれないので2を1かのように扱う
    // 0,1が答えのとき，2は0として扱ってもよい(mod 2で計算)

    // 1が存在するか
    bool has1 = false;
    for(char c : S) {
        A.push_back(c - '0');
        if(c == '1') has1 = true;
    }
    // mod2 なので和と差が同じ操作になる，絶対値が恒等変換になる．
    for(int &a : A) {
        if(has1) a %= 2;
        else a /= 2;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans ^= A[i] & SierpinskiGasket(N - 1, i);
    }
    if(ans && has1) cout << 1 << endl;
    else if(ans && !has1) cout << 2 << endl;
    else if(!ans) cout << 0 << endl;
    return 0;
}

