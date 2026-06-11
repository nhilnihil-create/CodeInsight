#include <bits/stdc++.h>

#define endl '\n'
#define PB push_back
#define PF push_front
#define MP make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;

int main(){
    ios_base::sync_with_stdio(false); //cin.tie(nullptr); cout.tie(nullptr);
    string s, t;
    cin >> s >> t;
    
    int ans = INF;
    for (int i = 0; i <= s.size() - t.size(); i++) {
        int count = 0;
        for (int j = 0; j < t.size(); j++) {
            if (s[i + j] != t[j])
                count++;
        }
        ans = min(ans, count);
    }
    cout << ans;
    return 0;
} 
