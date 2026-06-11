#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod=1000000007;
//head
const int nax = 1e5+2;
int st[60][nax];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        st[0][i] = i;
        st[1][i] = i + (s[i] == 'R' ? 1 : -1);
    }

    for(int i = 2; i <= 59; i++) {
        for(int j = 0; j < n; j++) {
            int nxt = st[i-1][j];
            st[i][j] = st[i-1][nxt];
        }
    }

    vector<int> cnt(n,0);
    for(int i = 0; i < n; i++) {
        cnt[st[59][i]]++;
    }
    trav(c,cnt) cout << c << " ";
    cout << endl;

    return 0;
}
