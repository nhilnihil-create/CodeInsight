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
    int n, m; 
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> ans;
    ans.push_back(n);
    int now = n;
    while(1) {
        int l = m;
        while(now-l<0||s[now-l]=='1') l--;
        if(l == 0) {
            cout << -1 << endl;
            return 0;
        }
        now -= l;
        ans.push_back(now);
        if(now == 0) break;        
    }
    reverse(ans.begin(), ans.end());
    int S = ans.size();
    for(int i = 0; i < S-1; i++) {
        cout << ans[i+1]-ans[i] << " ";
    }
    cout << endl;
}