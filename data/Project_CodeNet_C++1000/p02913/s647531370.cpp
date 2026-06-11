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
    int n; cin >> n;
    string s; cin >> s;
    unsigned long long b = 100000007;
    unsigned long long mod = (1LL<<61)-1;
    int ans = 0;
    repr(i,1,n/2+1){
        unsigned long long b_pow = 1;
        rep(j,i){
            b_pow *= b;
        }
        map<unsigned long long, int> hashs;
        unsigned long long hash = 0;
        rep(j,i) hash = hash*b+s[j];
        hashs[hash] = 0;
        //cout << hash << endl;
        repr(j,1,n-i+1){
            hash = hash*b+s[j+i-1]-s[j-1]*b_pow;
            if(hashs.count(hash)){
                if(hashs[hash]+i <= j){
                    ans = max(ans,i);
                    break;
                }
            }
            else hashs[hash] = j;
            //cout << i << " " << j << " " << ans << endl;
        }
    }
    cout << ans << endl;
    
}

