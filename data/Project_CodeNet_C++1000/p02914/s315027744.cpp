#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define pb push_back
#define mp make_pair
#define taskname "A"

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 2e5 + 5;

ll basis[60];
ll all = 0;

int n;
void add(ll x){
    for(int i = 59 ; i >= 0 ; --i){
        if((all >> i) & 1)continue;
        if((x >> i) & 1){
            if(basis[i])x ^= basis[i];
            else {
                basis[i] = x;
                return;
            }
        }
    }
}
ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        ll x;cin >> x;
        a[i] = x;
        all ^= x;
    }
    for(int i = 1 ; i <= n ; ++i){
        add(a[i]);
    }
    ll res = 0;
    for(int i = 59 ; i >= 0 ; --i){
        if(!((all >> i) & 1) && !((res >> i) & 1)){
            if(basis[i]){
                res ^= basis[i];
            }
        }
    }
    cout << res + (all ^ res);
}
