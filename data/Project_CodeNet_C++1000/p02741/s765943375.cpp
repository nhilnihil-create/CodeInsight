#include <bits/stdc++.h>

using namespace std;

#define INF 100010001000
#define MOD 1000000007
#define int long long int
#define maxn 100
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)

typedef pair<int, int> P;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int mpow(int N, int P, int M)  //繰り返し自乗法
{
    if (P == 0)
        return 1;
    if (P % 2 == 0) {
        int t = mpow(N, P / 2, M);
        return t * t % M;
    }
    return N * mpow(N, P - 1, M) % M;
}

int counter(int x) {           //bit計算
    if (x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}

vector<bool> prime(maxn + 1, true); //素数テーブル
void prime_table(void) {
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (!prime[i]) {
            continue;
        }
        for (int j = i + i; j <= maxn; j += j + i) {
            prime[j] = false;
        }
    }
}

bool IsPrime(int num) {   //素数判定
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

signed main() {
    string S = "1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51";
    rep(i, S.length()) {

    }
    int K;
    cin >> K;
    int c = 0;
    if (K == 32) {
        cout << 51 << endl;
        return 0;
    }
    rep(i, S.length()) {
        if (S[i] == ',') {
            c++;
        }
        if (c == K) {
            if (S[i - 2] == ' ' || c == 1) {
                cout << S[i - 1] << endl;
            } else {
                cout << S[i - 2] << S[i - 1] << endl;
            }
            break;
        }
    }
}
