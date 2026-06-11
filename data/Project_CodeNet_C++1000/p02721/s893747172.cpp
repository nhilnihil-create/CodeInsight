#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> l(n, -1), r(n, -1);
    int nextl = 0, nextr = n-1;
    int cntl = 1, cntr = 0;
    for(int i = 0; i < n; i++) {
        if(nextl <= i && s[i] == 'o') {
            l[i] = cntl++;
            nextl = i+c+1;
        }
        if(l[i] == k) break;
    }
    for(int i = n-1; i >= 0; i--) {
        if(nextr >= i && s[i] == 'o') {
            r[i] = (k-cntr++);
            nextr = i-c-1;
        }
        if(r[i] == 1) break;
    }
    for(int i = 0; i < n; i++) {
        if(l[i] != -1 && l[i] == r[i]) cout << i+1 << endl;
    }
}