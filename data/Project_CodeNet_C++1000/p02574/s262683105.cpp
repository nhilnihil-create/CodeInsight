        #include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;

 
const ll INF = 1e12;
const ll N =(1e6+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

int a[N];
vector<int> ma[N];
void solve(){
    int n;
    cin >> n;   
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
        int x = a[i];
        bool done = false;
        while(x%2==0){
            if(!done)
                ma[2].pb(i);
            done =true;
            x>>=1ll;
        }
        for(int j =3;j<=sqrt(x);j+=2){
            done = false;
            while(x%j==0){
                if(!done)
                    ma[x].pb(i);
                done = true;
                x /= j;
            }
        }
        if(x > 2){
            if(ma[x].empty() || ma[x].back() != i)
                ma[x].pb(i);
        }
    } 
    bool ok  =true;
    for(int i = 1;i<=1000000;i++){
        ok &= (ma[i].size() < 2);
    }
    if(ok){
        cout << "pairwise coprime\n";
        return;
    }
    int g = a[1];
    for(int i =2;i<=n;i++){
        g = __gcd(g,a[i]);
    }
    if(g == 1){
        cout << "setwise coprime\n";
        return;
    }
    cout << "not coprime\n";

}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     // freopen(".in","r",stdin);freopen(".out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}