#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<62;
const int INF = 1<<30;
const double PI=acos(-1);
ll mod = 1000000007;
int main()
{
    int n;
    ll ans=1;
    cin >>n;
    vector<ll>last(1000010,0LL);
    last[0]=3LL;
    int bef;
    rep(i,n){
        cin>>bef;
        last[bef+1]++;
        
        ans*=(last[bef]);
        last[bef]--;
        ans%=mod;
        
       // clog<<ans<<" ( "<<last[bef]<<" "<<last[bef+1]<<endl;
        if(ans<0){
            cout<<"0"<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}