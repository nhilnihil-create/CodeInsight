#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

template<class base_t, class func = function<base_t(const base_t&, const base_t&)>>
class mqueue
{
private:
    vector<pair<base_t, base_t>> s1, s2;
    func f;

    void move()
    {
        while(!s2.empty())
        {
            base_t x = s2.back().first;
            s2.pop_back();
            
            if(s1.empty()) s1.emplace_back(x, x);
            else s1.emplace_back(x, f(x, s1.back().second));
        }
    }

public:
    mqueue(const func& _f) { f = _f;}
    
    void pop() { if(s1.empty()) move(); s1.pop_back();}
    void push(base_t x)
    {
        if(s2.empty()) s2.emplace_back(x, x);
        else s2.emplace_back(x, f(x, s2.back().second));
    }
    
    base_t front() { if(s1.empty()) move(); return s1.back().first;}	
    base_t get()
    {
        if(!s1.empty() && !s2.empty())
            return f(s1.back().second, s2.back().second);
        else if(!s1.empty())
            return s1.back().second;
        else
            return s2.back().second;
    }
    
    int size() { return LEN(s1) + LEN(s2);}
    bool empty() { return size() == 0;}
    void clear() { s1.clear(); s2.clear();}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
    int n, m; cin >> n >> m;
    string s; cin >> s;

    if(s[n] == '1' || s[0] == '1')
    {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> dp(n + 1);
    vi p(n + 1);

    mqueue<pair<ll, int>> q([&](pair<ll, int> a, pair<ll, int> b){ return min(a, b);});

    dp[0] = p[0] = 0;
    q.push({0, 0});

    for(int i = 1; i <= n; i++)
    {
        if(LEN(q) > m) q.pop();
        if(s[i] == '1') dp[i] = INF<int>;
        else dp[i] = 1 + q.get().first, p[i] = q.get().second;
        q.push({dp[i], i});
    }

    if(dp[n] >= INF<int>) cout << -1 << endl;
    else
    {
        vi ans;
        
        while(n)
        {
            ans.emplace_back(n - p[n]);
            n = p[n];
        }

        reverse(ALL(ans));

        for(int i = 0; i < LEN(ans); i++)
            cout << ans[i] << " \n"[i == LEN(ans) - 1];
    }

    return 0;
}