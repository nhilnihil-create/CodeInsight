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
    int n,k, cnt;
    string s;
    cin >> n >> k >> s;
    char prev = s[0];

    cnt = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != prev) cnt++;
        prev = s[i];
    }
    while(k > 0 && cnt > 2){
        cnt -= 2;
        k--;
    }
    if(k > 0 && cnt == 2){
        cnt--;
    }
    cout << n - 1 - (cnt - 1) << endl;
    return 0;
}
