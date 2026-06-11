// Template //
#include<bits/stdc++.h>
using namespace std;

// マクロ //
#define rep(i,N) for(int i = 0; i < N; i++)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define cou(x) cout << x << endl
#define y() cout << "Yes" << endl
#define n() cout << "No" << endl
#define Y() cout << "YES" << endl
#define N() cout << "NO" << endl
#define x2(x) x * x

// 型エイリアス //
using lint = long long;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;

// 関数 //
int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// End of Template //

int main() {

	int N;
	cin >> N;

    lint sum = 0;
    vector<long long int> vec(N);
	int p;
	rep(i, N) {
		cin >> p;
		vec[i] = p;
        sum += p;
	}
    lint half = sum % 2 == 0 ? sum / 2 : sum / 2 + 1;
    lint su = 0;
    int i = 0;
    while (su < half) {
        su += vec[i];
        i++;
    }
    i--;
    if (su - vec[i] > sum - su) {
        cout << 2 * (vec[i] - su) + sum << endl;
    }
    else if(su - vec[i] < sum - su) {
        cout << 2 * su - sum << endl;
    }
    else {
        cou(vec[i]);
    }
}