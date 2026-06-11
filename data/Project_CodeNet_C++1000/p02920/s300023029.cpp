#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
struct edge{int to;ll cap;int rev;};
int main(){
    ll n;
    cin>>n;
    int n2 = 1<<n;
    vector<ll> a(n2);
    rep(i,n2) cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll> s;
    s.push_back(a.back());
    a.back() = -1;
    rep(i,n){
        vector<ll> p = s;
        sort(p.begin(),p.end());
        int ai = n2 - 1;
        while(p.size() > 0 && ai >= 0){
            if(a[ai] == -1){
                --ai;
                continue;
            }
            if(a[ai] < p.back()){
                s.push_back(a[ai]);
                p.pop_back();
                a[ai] = -1;
            }
            --ai;
        }
        if(p.size() > 0){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}