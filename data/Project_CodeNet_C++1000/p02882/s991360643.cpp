#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int a, b, x, A, Z;
    double ans;
    cin >> a >> b >> x;

    A = pow(a, 2.0);

    Z = A * b - x;

    double c, cosk;
    if(x * 2 >= A * b){
        c = (double)Z * 2 / A;
        cosk = a / sqrt(pow(a, 2.0) + pow(c, 2.0));
    } else {
        c = (double)x * 2 / b / a;
        cosk = c / sqrt(pow(b, 2.0) + pow(c, 2.0)); 
    }
    cout << fixed << setprecision(10) << acos(cosk) * 180 / PI << endl;
    
    return 0;
}
