#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int         ll
typedef vector<int> vi;
#define test        int t; cin >> t; while(t--)
#define max(a,b)   (a>b?a:b)
#define min(a,b)   (a<b?a:b)
const int mod = 1000000007;

template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    for (T i : v) {
        out << i << " ";
    }
    return out;
}

int n, k, c;
string s;


int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> c >> s;

    vector<int> l(k), r(k);
    int i = 0, cnt = 0;
    while (i < n && cnt < k) {
        if (s[i] != 'x') {
            l[cnt] = i;
            cnt++;
            i += c+1;
        } else {
            i++;
        }
    }
    i = n - 1, cnt = k - 1;
    while (i >= 0 && cnt >= 0) {
        if (s[i] != 'x') {
            r[cnt] = i;
            cnt--;
            i -= (c+1);
        } else {
            i--;
        }
    }

    for (int i = 0; i < k; ++i){
            if(l[i]==r[i]){
                cout<<l[i]+1<<endl;
            }
    }

    return 0;
}