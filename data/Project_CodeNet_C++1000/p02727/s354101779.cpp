#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T>
struct CumulativeSum {
	vector<T> v;
	CumulativeSum(const vector<T> &vv) : v(vv.size()+1) {
		T sum = 0;
		for ( size_t i = 0; i < vv.size(); i++ ){
			sum += vv[i];
			v[i+1] = sum;
		}
	}
	
	// [l,r) の合計
	T range(int l, int r){
		return v[r]-v[l];
	}
};


ll x, y, a, b, c;


int main(){
	cin >> x >> y >> a >> b >> c;
	
	vector<ll> p(a);
	vector<ll> q(b);
	vector<ll> r(c);
	
	for ( int i = 0; i < a; i++ ){
		cin >> p[i];
	}
	for ( int i = 0; i < b; i++ ){
		cin >> q[i];
	}
	for ( int i = 0; i < c; i++ ){
		cin >> r[i];
	}
	
	auto f = [](ll l, ll r){return r<l;};
	sort(p.begin(),p.end(),f);
	sort(q.begin(),q.end(),f);
	sort(r.begin(),r.end(),f);
	
	// pの大きい方からX個、q の大きい方からY個を混ぜてソートする
	vector<ll> v(x+y);
	copy(p.begin(),p.begin()+x,v.begin());
	copy(q.begin(),q.begin()+y,v.begin()+x);
	sort(v.begin(),v.end(),f);
	
	
	CumulativeSum<ll> cv(v);
	CumulativeSum<ll> cr(r);
	
	ll score = 0;
	for ( int i = 0; i <= c && i <= x+y; i++ ){
		score = max( score, cv.range(0,x+y-i) + cr.range(0,i) );
	}
	
	
	cout << score << endl;
	
	return 0;
}


