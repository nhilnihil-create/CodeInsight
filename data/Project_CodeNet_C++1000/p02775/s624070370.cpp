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
int main() {
    const int INF = 1e8;
    string S;
    cin >> S;
    S = string("0") + S;
    reverse(WHOLE(S));
    int ans = 0, N = S.size();
    // i, c |-> i桁目まで計算終了して，キャリーがc
    vector2d<int> dp(N + 1, vector<int>(2, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int c = 0; c < 2; c++) {
            // その桁の支払い + 前の桁から借りた場合の1
            int n = S[i] - '0' + c;
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][c] + abs(n));
            // 上の桁から借りて10返済
            n -= 10;
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][c] + abs(n));
        }
    }
    cout << dp[N][0] << endl;
    return 0;
}

