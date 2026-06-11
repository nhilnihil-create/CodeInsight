#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             2e16
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>


#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())


#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);

const int N = 100005;
int n , ara[N], pos[N];
int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> ara[i] , pos[ara[i]] = i;

    set<int>st;
    st.insert(0);
    st.insert(n + 1);
    LL ans = 0;
    for(int i = n;i >= 1;i--){
        auto rt = st.lower_bound(pos[i]);
        auto lt = rt;lt--;
        if(rt != --st.end()){
            int r1 = *rt;
            int r2 = *(++rt);
            LL R = abs(r2 - r1) ;
            LL L = abs(pos[i] - *lt) ;
            ans = ans + (L * R * i);
            --rt;
        }
        if(lt != st.begin()){
            int l2 = *lt;
            int l1 = *(--lt);
            LL L = abs(l1 - l2) ;
            LL R = abs(pos[i] - *rt);
            ans = ans + (L * R * i);
        }
        st.insert(pos[i]);
    }
    cout << ans << "\n";

}

