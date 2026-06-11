#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<int> A;
    Rep(i, N) {
        int a;
        cin >> a;
        A.push(a);
    }
    Rep(i, M) {
        int a = A.top();
        A.pop();
        A.push(a / 2);
    }
    ll ans = 0;
    Rep(i, N) {
        ans += A.top();
        A.pop();
    }
    cout << ans << endl;
    return 0;
}