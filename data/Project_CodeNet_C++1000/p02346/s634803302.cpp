#define MYDEBUG
#include <bits/stdc++.h>

#ifdef MYDEBUG
#define dbp(x) cout<<#x<<": "<<x<<endl
#define dbp2(x,y) cout<<#x<<","<<#y<<": "<<x<<","<<y<<endl
#define dbp3(x,y,z) cout<<#x<<","<<#y<<","<<#z<<": "<<x<<","<<y<<","<<z<<endl
#define dbp4(w,x,y,z) cout<<#w<<","<<#x<<","<<#y<<","<<#z<<": "<<w<<","<<x<<","<<y<<","<<z<<endl
#define ifcin(x) std::ifstream cin(x)
#else
#define dbp(x)
#define dbp2(x,y)
#define dbp3(x,y,z)
#define dbp4(w,x,y,z)
#define ifcin(x)
#endif
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for(int i=from; i<to; ++i)
#define REP(i, from, to) for(int i=from; i<=to; ++i)
#define EPS = 1e-14;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::min;
using std::swap;
using std::string;
using std::fill;
using std::pair;
using std::sort;
using std::reverse;
using std::pair;
using std::greater;
using std::priority_queue;
using std::ostream;
typedef std::complex<int> P;

template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i] << endl;
	}
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "[";
	size_t last = v.size() - 1;
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i];
		if (i != last) {
			out << ",";
		}
	}
	out << "]";
	return out;
}

const int MAX_N = 1 << 19;
//?????°???????????¨???????????°??????????????????
int SIZE, dat[MAX_N], lazy[MAX_N];

//?????????
void init(int n_) {
	//?°????????????????????´???°???2???????????????
	//n_????¬???????????´???°, SIZE???????????°, 2*SIZE-1??????????´???°
	SIZE = 1;
	while (SIZE < n_) {
		SIZE *= 2;
	}
	//??????????????????0???
	for (int i = 0; i < 2 * SIZE - 1; i++) {
		dat[i] = 0;
		lazy[i] = 0;
	}
}

void lazy_evaluate(int k) {
	dat[k] += lazy[k];
	if (k < SIZE - 1) {
		lazy[k * 2 + 1] += lazy[k];
		lazy[k * 2 + 2] += lazy[k];
	}
	lazy[k] = 0;
}

void update_add_range(int a, int b, int k, int l, int r, int x) {
	if (r <= a || b <= l) {
		return;
	}
	if (a <= l && r <= b) {
		lazy[k] += x;
		lazy_evaluate(k);
	} else {
		lazy_evaluate(k);
		update_add_range(a, b, k * 2 + 1, l, (l + r) / 2, x);
		update_add_range(a, b, k * 2 + 2, (l + r) / 2, r, x);
		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		return;
	}
}

int getSum(int a, int b, int k, int l, int r) {
	if(r<=a || b<=l){
		return 0;
	}
	if(a<=l && r<=b){
		return dat[k];
	}else{
		int vl = getSum(a, b, 2*k+1, l, (l+r)/2);
		int vr = getSum(a, b, 2*k+2, (l+r)/2, r);
		return vl + vr;
	}
}

int add(int k, int x){
	k += SIZE - 1;
	dat[k] += x;
	while(k > 0){
		k = (k - 1) / 2;
		dat[k] = dat[2*k+1] + dat[2*k+2];
	}
}



int N, Q;
void solve() {
	//ifcin("/storage/emulated/0/AppProjects/AtCoder/jni/in.txt");
	cin >> N >> Q;
	init(N);
	rep(q,0,Q)
	{
		int com, x, y;
		cin >> com >> x >> y;
		if (com == 0) {
			add(x-1, y);
		} else {
			cout << getSum(x-1, y-1+1, 0, 0, SIZE) << endl;
		}
	}
}

int main() {
	solve();
}