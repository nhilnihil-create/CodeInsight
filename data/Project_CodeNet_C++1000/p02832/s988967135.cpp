#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define pb push_back
#define mp make_pair 
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define rrep(i,a,b) for(int i = a; i >=b; i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define sq(a) (a)*(a)
#define nl "\n"
#define all(x) (x).begin(),(x).end()
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> indexed_set;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using ii = pair<int, int>;
using pli = pair<ll, int>;
using vi = vector<int>;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using pil = pair<int,ll>;
using vvi = vector<vi>;
using vpi = vector<ii>;

const int N = 100100;
ll mod=1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n-1){
        cin>>a[i];
    }
    int tosodh = 1;
    int cnt = n;
    rep(i,0,n-1){
        if(a[i]==tosodh){
            tosodh = a[i]+1;
            cnt--;
        }
    }
    if(cnt==n){
        cout<<"-1"<<nl;
    }
    else
        cout<<cnt<<nl;
    return 0;
}
