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
using ii = pair<int,ll>;

void err(istream_iterator<string> it) {cerr << endl;}
template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}




const int dx[] = {0, -1,1,0,1,-1, 1,-1};
const int dy[] = {1 , 0, 0, -1,1,-1,-1, 1};

const double EPS = 1e-9;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
const int N = 2e5 + 5;
const ll CONSTANT = 9e18 + 7;




int n, a[N],k;
bool check(int mid){
        int x = k;
        for(int i = 0; i < n; ++i){
            if(a[i] <= mid )continue;
            x -= ((a[i] + mid - 1)/mid - 1);
        }
        return x >= 0 ? true : false;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    int lo = 1, hi = 1e9, mid , ret = -1;
    while(lo <= hi){
        mid = lo + hi >> 1;
        if(check(mid)){
            hi = mid - 1;
            ret = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout << ret << '\n';

    return 0;
}
