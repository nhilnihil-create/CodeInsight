#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}}; ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}
int main() {
    int N;
    cin >> N;
    vector<i64> A(N), B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    sort(WHOLE(A)), sort(REV_WHOLE(B));
    i64 ans = 0;
    if(N % 2 == 0) { // 偶数
        i64 m_min = A[N / 2] + A[N / 2 - 1];
        i64 m_max = B[N / 2] + B[N / 2 - 1];
        ans = m_max - m_min + 1;
    } else { // 奇数
        i64 m_min = A[(N - 1) / 2];
        i64 m_max = B[(N - 1) / 2];
        ans = m_max - m_min + 1;
    }
    cout << ans << endl;
    return 0;
}