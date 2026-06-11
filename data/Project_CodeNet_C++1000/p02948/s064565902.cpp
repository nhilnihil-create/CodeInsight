#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int)1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) cerr << ", "; __print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; __print(x)


vector<int> adj[200005];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    i64 a, b;
    for(int i = 0; i < n; i++) {
        scanf("%lld%lld", &a, &b);
        if(m-a>=0) adj[m-a].push_back(b);
    }
    priority_queue<i64> p;
    i64 ans = 0;
    for(int i = m-1; i >= 0; i--) {
        for(i64 k : adj[i]) {
            // dbg(i, k);
            p.push(k);
        }
        if(p.size()) {
            ans += p.top();
            // dbg(i, p.top());
            p.pop();
        }
    }
    printf("%lld\n", ans);
}
