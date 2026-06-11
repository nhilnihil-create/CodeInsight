#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector< int > >;
using pi = pair<int,int>;
using st = set<int>;
using kiwi = queue<int>;
using mp = map<int,int>;
using ump = unordered_map<int,int>;
#define MOD 1000000007
const ll mx = 1e5+123;
#define REP(i,n) for (ll i=1;i<=n;++i)

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

#define dbg(args...) do {cerr<<#args<<" : "; faltu(args); } while(0)
void faltu ()  {        cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr<<arg<< ' ';faltu(rest...);}

#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
    fastio;
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    string za; cin>>za;

    for(ll i=0;i<=za.size()-3;++i)
    {
        if((za[i]>=97&&za[i]<=122)&&(za[i+1]>=97&&za[i]<=122)&&(za[i+2]>=97&&za[i]<=122)){cout<<za.substr(i,3)<<endl; return 0;
        }
    }

return 0;
}
