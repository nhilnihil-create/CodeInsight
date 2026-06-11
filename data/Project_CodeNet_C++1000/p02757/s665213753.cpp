#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<sstream>
#include<cmath>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
typedef long long int ll;
typedef long double ld;
const ll INF = 1LL << 60;
const int inf = (1 << 30);
const int MOD = 1000000007;
ll n, k, ans = 0, h = 1, W, sum = 0, p;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    int N, P; string S;
    cin >> N >> P >> S;
    if (P == 2 || P == 5) {
        for (int i = 0; i < N; i++) {
            if ((S[i] - '0') % P == 0) ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }
    vector<int> ama(P,0);
    int count = 1,now = 0; ama[0]++;
    rrep(i,N) {
        int a = (S[i] - '0') * count % P;
        now = (now + a) % P;
        ans += ama[now]; ama[now]++;
        count = count * 10 % P;
    }
    cout << ans << endl;
}