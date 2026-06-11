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
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int n,k,c; cin >> n >> k >> c;
    string s; cin >> s;
    int now = 0;
    int cnt = 0;
    vector<bool> ok(n,false);
    while(now < n){
        if(s[now] == 'o'){
            ok[now] = true;
            cnt++;
            now += c+1;
        }
        else now++;
    }
    if(cnt == k){
        int last = n-1;
        int now = 1;
        vector<int> v(2*n);
        for(int i = n-1; i >= 0; i--){
            if(s[i] == 'x'){
                if(i != n-1) v[i] = v[i+1];
            }
            else if(i <= last-c-1){
                last = i;
                now++;
                v[i] = now;
            }
            else{
                v[i] = now;
            }
        }
        //rep(i,n) cout << v[i] << " ";
        vector<int> ans;
        int cnt = 0;
        int last2 = -1;
        rep(i,n){
            if(s[i] == 'x') continue;
            int nowans = cnt+(last2 == -1?v[i+1]:v[max(i+1,last2+c+1)]);
            if(nowans < k) ans.push_back(i+1);
            if(ok[i]){
                cnt++;
                last2 = i;
            }
        }
        rep(i,ans.size()) cout << ans[i] << endl;
    }
}

