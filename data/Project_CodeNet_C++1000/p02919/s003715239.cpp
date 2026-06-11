#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define USE_LLONG_AS_INT
#ifdef USE_LLONG_AS_INT
#define int long long
#define inf (1ll<<60)
#else
#define inf (1<<30)
#endif
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=(n)-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())

using namespace std;

const int mod=1e9+7;
const string sp=" ";

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

void run(){
    int n;
    cin>>n;
    vi p(n);
    rep(i,n)cin>>p[i];
    vi inv(n+1);
    rep(i,n)inv[p[i]]=i+1;
    multiset<int> st;
    st.insert(0);
    st.insert(0);
    st.insert(n+1);
    st.insert(n+1);
    int ans=0;
    for(int i=n;i>0;i--){
        int idx=inv[i];
        auto r1=st.lower_bound(idx);
        auto r2=r1;
        r2++;
        auto l1=r1;
        l1--;
        auto l2=l1;
        l2--;
        ans+=i*((*r2-*r1)*(idx-*l1)+(*l1-*l2)*(*r1-idx));
        st.insert(idx);
    }
    cout<<ans<<endl;
}