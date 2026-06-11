    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #define fastio() ios_base::sync_with_stdio(false);
    #define rmod(x, y) ((((x)%(y))+(y))%(y))
    using namespace std;
    using namespace __gnu_pbds;
    typedef long long ll;
    typedef long double ld;
    template<typename T, typename R = null_type, typename C = less<T>>
    tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update> ordered_set(){
    	return tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update>();
    }
     
    const int maxn = 1e5+5;
    int x, y, a, b, c, k;
    deque<int> p, q, r;
     
    int main(){
    	scanf("%d %d %d %d %d", &x, &y, &a, &b, &c);
    	for(int i = 0; i<a; i++) scanf("%d", &k), p.push_back(k);
    	for(int i = 0; i<b; i++) scanf("%d", &k), q.push_back(k);
    	for(int i = 0; i<c; i++) scanf("%d", &k), r.push_back(k);
    	sort(p.begin(), p.end());
    	sort(q.begin(), q.end());
    	sort(r.begin(), r.end(), greater<int>());
    	while(p.size()>x) p.pop_front();
    	while(q.size()>y) q.pop_front();
    	while(r.size()){
    		int mn = min(p.front(), q.front());
    		if (r.front()<=mn) break;
    		if (p.front()<q.front()) p.push_back(r.front()), p.pop_front(), r.pop_front();
    		else q.push_back(r.front()), r.pop_front(), q.pop_front();
    	}
    	ll ans = 0;
    	for(int v: p) ans+= (ll)v;
    	for(int v: q) ans+= (ll)v;
    	printf("%lld\n", ans);
    	return 0;
    }