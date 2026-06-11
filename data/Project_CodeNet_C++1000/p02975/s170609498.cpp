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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,int> mp;
    rep(i,n) mp[a[i]]++;
    int m = mp.size();
    if(m >= 4){
        cout << "No" << endl;
        return 0;
    }
    if(m == 1){
        if(mp[0] == n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(m == 2){
        if(n%3 == 0 && mp[0] == n/3) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        int t = 0;
        bool ok = true;
        for(auto u : mp){
            t ^= u.first;
            if(u.second != n/3) ok = false;
        }
        if(t == 0 && ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

