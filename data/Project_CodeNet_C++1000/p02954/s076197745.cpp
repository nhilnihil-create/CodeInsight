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

const double PI = 3.1415926535897932;
const int INF = (int)1e9;
const ll LINF = 1e18;
const int IMOD = 1000000007;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std; 

int main(void)
{
    string s;
    cin >> s;

    v_int ans(s.size());
    
    int r = 0;
    irep(i, s.size()-1) {
        if(s[i] == 'R') r++;
        if(s[i] == 'R' && s[i+1] == 'L') {
            ans[i] += (r+1)/2;
            ans[i+1] += (r)/2;
            r = 0;
        }
    }
    
    int l = 0;
    irrep2(i, 1, s.size()-1) {
        if(s[i] == 'L') l++;
        if(s[i-1] == 'R' && s[i] == 'L') {
            ans[i] += (l+1)/2;
            ans[i-1] += (l)/2;
            l = 0;
        }
    }
    irep(i, s.size()) {
        printf("%d ", ans[i]);
    }
    return 0;
}
/** atcoder **/

