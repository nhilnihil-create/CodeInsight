#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

void dfs(string s, ll n_options, ll n){

    if(s.size() == n){
        cout << s << endl;
        return;
    }

    rep(i, n_options){
        char c = 'a' + i;
        string s_next = s;
        s_next.push_back(c);

        if(i == n_options - 1){
            dfs(s_next, n_options + 1, n);
        }
        else{
            dfs(s_next, n_options, n);
        }
    }
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin >> n;

    string s = "a";
    dfs(s, 2, n);

    return 0;
}