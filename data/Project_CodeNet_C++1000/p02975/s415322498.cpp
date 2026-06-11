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
    int n;
    cin >> n;

    map<int, int> cercle;
    irep(i, n) {
        int in;
        cin >> in;
        cercle[in]++;
    }

    string ans = "No";
    if(cercle.size() == 1) {
        if(cercle.find(0) != cercle.end()) {
            ans = "Yes";
        }
    } else if(n%3 == 0 && cercle.size() == 3) {
        int x = 0;
        bool ok = true;
        for(auto c : cercle) {
            x ^= c.first;    
            if(c.second != n/3) {
                ok = false;
            }
        }
        if(ok & !x) { 
            ans = "Yes";
        }
    } else if(n%3 == 0 && cercle.size() == 2) {
        if(cercle[0] == n/3) {
            ans = "Yes";
        }
    } else {
        ans = "No"; 
    }
    cout << ans << endl;
    return 0;
}
/** atcoder **/

