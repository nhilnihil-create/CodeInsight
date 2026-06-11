#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)

typedef long long ll;
typedef std::vector<int> v_int;
typedef std::vector<v_int > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<v_ll > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<v_string > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<v_bool > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

const double PI = 3.14159265359;
const int INF = (int)1e9;
const ll LINF = 1e18;
const int IMOD = 1000000007;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std; 

int main(void)
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    s += "#####";
    n += 5;

    int dpA[n], dpB[n];
    irep(i, n) {
        dpA[i] = 0;
        dpB[i] = 0;
    }
    dpA[a] = 1; 
    dpB[b] = 1;

    irep(i, n) {
        if(s[i] == '.') { 
            dpA[i+1] += dpA[i];
            dpB[i+1] += dpB[i];
        }
        if(s[i+1] == '.') { 
            dpA[i+2] += dpA[i];
            dpB[i+2] += dpB[i];
        }
    }

    if(c <= d) {
        if(dpA[c] && dpB[d]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        int idx = b;
        while(idx < d) {
            while(idx < d) {
                if(s[idx-2] == '.' && s[idx-1] == '.' && s[idx] == '.' && dpB[idx]) {
                    break;
                } else {
                    idx++;
                }
            }
            if(dpA[idx-1] && dpA[idx+1] && dpA[c] && dpB[d]) {
                cout << "Yes" << endl;
                return 0;
            } else {
                idx++;
            }
        }
        cout << "No" << endl;
    }
    //irep(i, n) { cout << dp[0][i] << ","; } cout << endl;
    return 0;
}
/** atcoder **/

