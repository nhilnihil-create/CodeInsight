#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
const ll MOD = 1e9+7;
vi alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main() {
    int n;
    cin >> n;
    vi a(n + 1);
    repp(i, n)cin >> a[i];
    vb ans(n + 1, false);
    for (int i = n; i >= 1;i--) {
        int k = n / i;
        int sum = 0;
        while (k > 1) {
            if (ans[i * k]) sum++;
            k--;
        }
        if (sum % 2 != a[i]) ans[i] = true;
    }
    int count = 0;
    repp(i, n) {
        if (ans[i])count++;
    }
    cout << count << endl;
    repp(i, n) {
        if (ans[i])cout << i << " ";
    }
}