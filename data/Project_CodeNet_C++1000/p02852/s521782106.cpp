#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

template <class M> class segment_tree{
public:
	typedef typename M::value_type value_type;
	size_t n;
	vector<value_type> v;
	value_type e = M::unit();
	segment_tree(size_t size){
		n = 1;
		while(n < size) n <<= 1;
		v.resize(2*n, e);
		for(size_t i=1; i<n+size; ++i) v[i] = e;
	}
	segment_tree(vector<value_type> a){
		size_t size = a.size();
		n = 1;
		while(n < size) n <<= 1;
		v.resize(2*n, e);
		for(size_t i=0; i<size; ++i) v[n+i] = a[i];
		for(size_t i=n-1; i>0; --i) v[i] = M::operate(v[2*i], v[2*i+1]);
	}
	void point_update(size_t k, value_type val){
		k += n;
		v[k] = val;
		k >>= 1;
		while(k > 0){
			v[k] = M::operate(v[2*k], v[2*k+1]);
			k >>= 1;
		}
	}
	void point_operate(size_t k, value_type lval){
		k += n;
		v[k] = M::operate(lval, v[k]);
		k >>= 1;
		while(k > 0){
			v[k] = M::operate(v[2*k], v[2*k+1]);
			k >>= 1;
		}
	}
	value_type range_get(size_t l, size_t r){ // [l, r)
		value_type lres = e;
		value_type rres = e;
		l += n;
		r += n;
		while(l < r){
			if(l & 1){
				lres = M::operate(lres, v[l]);
				++l;
			}
			if(r & 1){
				--r;
				rres = M::operate(v[r], rres);
			}
			l >>= 1;
			r >>= 1;
		}
		return M::operate(lres, rres);
	}
	value_type operator[](size_t k){
		return v[k+n];
	}
};
struct plus_monoid{
	using value_type = Int;
	static value_type unit(){
		return 0;
	}
	static value_type operate(value_type l, value_type r){
		return l + r;
	}
};
struct min_monoid{
	using value_type = Int;
	static value_type unit(){
		return 1e9;
	}
	static value_type operate(value_type l, value_type r){
		return min(l, r);
	}
};


int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	Int n, m; cin >> n >> m;
	string s; cin >> s;
	vector<Int> a(n+1, 1e9);
	a[n] = 0;
	segment_tree<min_monoid> st(a);
	for(Int i=n-1; i>=0; --i)
		if(s[i] == '0'){
			a[i] = st.range_get(i+1, min(i+m+1, n+1)) + 1;
			st.point_update(i, a[i]);
		}
	if(a[0] > 1e8){
		cout << -1 << "\n";
		return 0;
	}
//	for(Int i=0; i<=n; ++i)
//		cout << i << " " << a[i] << "\n";
	vector<Int> ans;
	for(Int i=0; i<=n; ++i){
		for(Int j=1; j<=m&&i+j<=n; ++j){
			if(a[i]-1 == a[i+j]){
				ans.push_back(j);
				i = i+j-1;
				break;
			}
		}
	}
	for(size_t i=0; i<ans.size(); ++i)
		cout << ans[i] << " \n"[i+1==ans.size()];
}