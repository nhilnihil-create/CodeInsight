#include <bits/stdc++.h>
using namespace std;
void print() {
    cout << endl;
}
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(tail) != 0)
        cout << " ";
    print(forward<Tail>(tail)...);
}
template <class T>
void print(vector<T> &vec) {
    for (auto &a : vec) {
        cout << a;
        if (&a != &vec.back())
            cout << " ";
    }
    cout << endl;
}
template <class T>
void print(vector<vector<T>> &df) {
    for (auto &vec : df) {
        print(vec);
    }
}
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define xrep(i, a, b) for (int i = int(a); i < int(b); ++i)
using ll = long long;
const int INF = 1001001001;

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;
    double pi = acos(-1);
    double theta = ((double)M*(1.0/(60.0*12.0))+(double)H/(double)12-(double)M/(double)60)*2*pi;
    if(theta>2*pi) {
        theta -= 2*pi;
    }
    double d = sqrt(B*B+A*A-2*A*B*cos(theta));
    printf("%.13lf\n", d);
    return 0;
}