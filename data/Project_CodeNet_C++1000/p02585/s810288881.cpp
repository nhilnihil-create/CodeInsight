#include<bits/stdc++.h>
#define ll long long
#define F(type, i, a, b) for(type i = a; i <= b; i ++)
#define RF(type, i, a, b) for(type i = a; i >= b;i --)
#define sz(a) sizeof(a)
#define deb(a) cerr<<" ["<<#a<<"->"<<a<<"] "
#define name(a) cerr<<" ["<<#a<<"->"
#define next_line cerr<<'\n'
#define all(a) a.begin(), a.end()
#define iter(it, s) for(auto it = s.begin(); it != s.end(); it ++)

using namespace std;

typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

ll INF = 1e18 + 1LL;

void solve()
{
    ll n, k;
    cin>>n>>k;
    ll Perm[n], cost[n];
    F(ll, i, 0, n - 1){
        cin>>Perm[i];
        Perm[i]--;
    }
    F(ll, i, 0, n - 1)
        cin>>cost[i];
    vector<vector<ll> > conn, ans_c;
    vector<int> comp(n, -1);
    int ls_c = 0;
    F(ll, i, 0, n - 1){
        stack<ll> st;
        if(comp[i] == (-1)){
            vector<ll> pu;
            st.push(i);
            while(!st.empty()){
                ll top = st.top();
                st.pop();
                pu.push_back(top);
                comp[top] = ls_c;
                if(comp[Perm[top] ] == (-1)){
                    st.push(Perm[top]);
                }
            }
            conn.push_back(pu);
            ls_c ++;
        }
    } 
    for(vector<ll> &v: conn){
        ll s = v.size();
        vector<ll> pu;
        ll add = 0LL, max_co;
        F(ll, j, 1, s){
            add += cost[v[j - 1] ];
            max_co = add;
            ll mov_add = add;
            F(ll, i, 1, s - 1){
                mov_add -= cost[v[i - 1]];
                mov_add += cost[v[(i + j - 1) % s]];
                max_co = max(max_co, mov_add);
            }
            pu.push_back(max_co);
        }
        ans_c.push_back(pu);
    }
    ll ans = -INF;
    for(vector<ll> &v: ans_c){
        ll size = v.size();
        if(v.back() <= 0LL){
            size = min(size, k);
            ans = max(ans, *max_element(v.begin(), v.begin() + size));
        }
        else{
            ll cyc = k / size, add = ((k % size) != 0LL)?*max_element(v.begin(), v.begin() + (k % size)):0LL;
            ans = max(ans, (cyc * v.back()) + add);
            if(cyc >= 1){
                ans = max(ans, ((cyc - 1LL) * v.back()) + *max_element(all(v)));
            }
        }
    }    
    cout<<ans<<'\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("Debug.txt", "w", stderr);
    #else
    #endif
        solve();
}
