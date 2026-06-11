#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int N,M; cin >> N >> M;
    string s; cin >> s;
    reverse(s.begin(),s.end());
    int now = 0;
    vector<int> ans;
    while(true){
        bool ok = false;
        for(int i = now+M; i >= now+1; i--){
            if(i <= N && s[i] == '0'){
                ans.push_back(i-now);
                now = i;
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << -1 << endl;
            return 0;
        }
        if(now == N) break;
    }
    reverse(ans.begin(),ans.end());
    rep(i,ans.size()) cout << ans[i] << " ";
    cout << endl;
}