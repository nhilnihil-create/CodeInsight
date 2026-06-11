#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
#define coutd(i) cout << std::fixed << std::setprecision(i)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Set = std::set<T>;
template<class T, class U>
using Map = std::map<T, U>;

template<class T>
using Graph = vector<vector<T>>;

const int INT_BIG = 1<<28;

int main() {
    string s, t;
    cin >> s >> t;
    ll slen = s.length();
    Map<char, vll> cmap;
    rep(i, slen) {
        char c = s[i];
            
        cmap[c].push_back(i);
    }

    ll ans = 1;
    ll nowpos = -1;
    int tlen = t.length();
    rep(i, tlen) {
        char c = t[i];
        if (cmap.find(c) == cmap.end()) {
            cout << -1 << endl;
            return 0;
        }

        int cmapvlen = cmap[c].size();
        // cout << "c" << c << cmap[c][0] << endl;
        if (nowpos >= cmap[c][cmapvlen - 1]) {
            ans++;
            nowpos = cmap[c][0];
        } else if (nowpos < cmap[c][0]) {
            nowpos = cmap[c][0];
        } else {
            int left = -1;
            int right = cmapvlen;
            while ((right - left) > 1) {
                int mid = left + (right - left) / 2;
                if (cmap[c][mid] <= nowpos) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            nowpos = cmap[c][right];
        }
        // cout << "n" << nowpos << endl;
        // cout << ans << endl;
    }
    cout << (ans-1)*slen + nowpos + 1 << endl;
}