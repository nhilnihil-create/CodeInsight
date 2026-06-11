#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T>
struct BIT{
    private:
        vector<T> array;
        const int n;
    public:
        BIT(int _n) : array(_n + 1, 0), n(_n) {}
        // [1, i], i is 1-indexed
        T sum(int i){
            T s = 0;
            while(i > 0){
                s += array[i];
                i -= i & -i;
            }
            return s;
        }
        // [i, j), i and j are 1-indexed
        T sum(int i, int j){
            T ret_i = sum(i-1);
            T ret_j = sum(j);
            return ret_j - ret_i;
        }
        // i is 1-indexed
        void add(int i, T x){
            while(i <= n){
                array[i] += x;
                i += i & -i;
            }
        }

        // debug
        void print(){
            for(int i = 1; i < (int)array.size(); ++i){
                cout << sum(i, i+1) << " ";
            }
            cout << endl;
        }
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll d, a;
	cin >> n >> d >> a;
	vector<P> v(n+1);
	rep(i,n) cin >> v[i+1].first >> v[i+1].second;
	sort(v.begin(), v.end());
	ll ans = 0, sum = 0;
	BIT<ll> bit(n+5);
	for(int i = 1; i <= n; ++i){
		ll x = v[i].first;
		ll h = v[i].second - (sum - bit.sum(i));
		if(h <= 0) continue;
		ll cnt = (h + a - 1) / a;
		ans += cnt;
		ll dam = a * cnt;
		sum += dam;
		int ok = i, ng = n+1;
		while(ng - ok > 1){
			int mid = (ok + ng) / 2;
			ll y = v[mid].first;
			if(y <= x + 2*d) ok = mid;
			else ng = mid;
		}
		bit.add(ok+1, dam);
	}
	cout << ans << endl;
	return 0;
}