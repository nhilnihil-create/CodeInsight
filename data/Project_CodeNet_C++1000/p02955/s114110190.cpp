#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 9e18;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    cin >> A;
    int sum = accumulate(A.begin(), A.end(), 0LL);
    vector<int> divisor;
    for (int i = 1; i <= sqrt(sum); i++) {
        if (sum % i == 0) {
            divisor.push_back(i);
            divisor.push_back(sum / i);
        }
    }
    sort(divisor.rbegin(), divisor.rend());
    for (int temp : divisor) {
        int count = 0;
        vector<int> move(N);
        for (int i = 0; i < N; i++) {
            count += A[i] % temp;
            move[i] = temp - A[i]% temp;
        }
        sort(move.begin(), move.end());
        if (count % temp != 0) continue;
        int sumK = 0;
        for (int i = 0; i < count / temp; i++) {
            sumK += move[i];
        }
        if (sumK > K) continue;
        cout << temp << endl;
        return 0;
    }
}
