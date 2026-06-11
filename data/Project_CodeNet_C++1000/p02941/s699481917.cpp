#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int         int64_t
#define ii          pair<int,int>
#define dd          pair<double,double>
#define vi          vector<int>
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define checkBit(v, p)      (v&(1LL << p))
#define loop(i,a,b) for(int i = a;i < int(b);i++)
#define x           first
#define y           second
using namespace std;

int inf = 2e9, mod = 998244353;


int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    int n; cin >> n;
    vi a(n), b(n);
    set<ii> st;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(a[i] != b[i])st.insert({b[i],i});
    }
    int sum = 0;
    for(;st.size();){
        auto it = st.rbegin();
        int cur = it->second;
        st.erase(*it);
        int times = (b[cur] - a[cur])/(b[(cur+1)%n] + b[(cur-1+n)%n]);
        if(times == 0) return cout << -1 << endl, 0;
        sum += times;
        b[cur] -= times * (b[(cur+1)%n] + b[(cur-1+n)%n]);
        if(b[cur] < a[cur]) return cout << -1 << endl, 0;
        if(b[cur] > a[cur]) st.insert({b[cur], cur});
    }
    cout << sum << endl;
    return 0;
}
