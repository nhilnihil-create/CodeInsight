#include <bits/stdc++.h>


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()


using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
using ll  = long long;

using point = complex<double>;


void err(istream_iterator<string> it) {cerr << endl;}
template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}




const int dx[] = {0, 0,1,-1,1,-1, 1,-1};
const int dy[] = {1,-1,0, 0,1,-1,-1, 1};

const double EPS = 1e-9;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
const int N = 5e3 + 5;



int n , m;
int a[N];
int b[N];
ll msk[6000];
ll dp[N][N];
vector<int> vec;
ll solve(int i , int mask){

    if(mask == (1<<n)-1)
            return 0;
    if(i == vec.size())
            return 1e16;
    ll &ret = dp[i][mask];
    if(~ret)
            return ret;
    ret = 1e16;
    ret = min(solve(i + 1,mask),ret);
    ret = min(solve(i + 1,mask | vec[i] ) + msk[vec[i]],ret);
    return ret;

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 6000; ++i)
        msk[i] = 1e16;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
            int x = 0,c;
            cin >> a[i] >> b[i];
            for(int j = 0; j < b[i]; ++j){
                cin >> c;
                --c;
                x |= (1 << c);
            }

            msk[x] = min(msk[x],1ll*a[i]);
    }
    for(int i = 0; i < (1 << n); ++i){

            if(msk[i] != 0)vec.push_back(i);
    }
    memset(dp,-1,sizeof dp);
   ll ret = solve(0,0);
   if(ret >= 1e16)cout << -1 << '\n';
   else cout << ret << '\n';
    return 0;
}
