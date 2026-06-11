#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};
using Vote = pair<ll,ll>;
using Unordered_map = unordered_map<Vote, int, pair_hash>;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define showvec(arr,a,b) for(ll i=a;i<b;i++) cout<<arr[i]<<" ";
#define read_input(arr,a,b) for(ll i=a;i<b;i++) cin>>arr[i];
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define SmooothOperatorrrrr()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                    \
    cout.tie(0);                   
#define deci(n) cout<<fixed<<setprecision(n)
const int mod=998244353;
const int mod2=1000000007;
#define M_PI 3.14159265358979323846
#define LL_MAX 9223372036854775807
#define MAXN 2000001
/**************************************************************************************************/
int main()
{
    SmooothOperatorrrrr();
    int n,x,t;cin>>n>>x>>t;
    int num=n/x;
    if(n%x)
        num++;
    cout<<num*t<<endl;
}