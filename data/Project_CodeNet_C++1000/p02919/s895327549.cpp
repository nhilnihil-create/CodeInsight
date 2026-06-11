#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
const LL INF = 1e18;

class SegmentTree {
private:
    int st_siz;
    vector<LL> ST_min, ST_max;

public:
    SegmentTree(int siz) {
        st_siz = 1;
        while(st_siz < siz) st_siz *= 2;
        ST_min.resize(2 * st_siz - 1, INF);
        ST_max.resize(2 * st_siz - 1, 0);
    }

    int get_size() {
        return st_siz;
    }

    void min_init(LL x) {
        for(int i = 0; i < 2 * st_siz - 1; i++) ST_min[i] = x;
    }

    void max_init(LL x) {
        for(int i = 0; i < 2 * st_siz - 1; i++) ST_max[i] = x;
    }

    void min_update(int i, LL x) {
        i += st_siz - 1;
        ST_min[i] = x;
        while(i > 0) {
            i = (i - 1) / 2;
            ST_min[i] = min(ST_min[i * 2 + 1], ST_min[i * 2 + 2]);
        }
    }

    void max_update(int i, LL x) {
        i += st_siz - 1;
        ST_max[i] = x;
        while(i > 0) {
            i = (i - 1) / 2;
            ST_max[i] = max(ST_max[i * 2 + 1], ST_max[i * 2 + 2]);
        }
    }

    LL RmQ(int a, int b, int k = 0, int l = 0, int r = -1, LL e = INF) {
        if (r == -1) r = st_siz;
        if (r <= a || b <= l) return e;
        if (a <= l && r <= b) return ST_min[k];
        else {
            LL m1 = RmQ(a, b, 2 * k + 1, l, (l + r) / 2, e);
            LL m2 = RmQ(a, b, 2 * k + 2, (l + r) / 2, r, e);
            return min(m1, m2);
        }
    }

    LL RMQ(int a, int b, int k = 0, int l = 0, int r = -1, LL e = 0) {
        if (r == -1) r = st_siz;
        if (r <= a || b <= l) return e;
        if (a <= l && r <= b) return ST_max[k];
        else {
            LL M1 = RMQ(a, b, 2 * k + 1, l, (l + r) / 2, e);
            LL M2 = RMQ(a, b, 2 * k + 2, (l + r) / 2, r, e);
            return max(M1, M2);
        }
    }

    int lower_bound_left(int a, int b, LL x, int k = 0, int l = 0, int r = -1) {
    	if (r == -1) r = st_siz;
    	if (ST_max[k] < x || r <= a || b <= l) return a - 1;
    	else if (k >= st_siz - 1) return (k - (st_siz - 1));
    	else {
    		int v = lower_bound_left(a, b, x, 2 * k + 2, (l + r) / 2, r);
    		if (v != a - 1) return v;
    		else {
    			return lower_bound_left(a, b, x, 2 * k + 1, l, (l + r) / 2);
    		}
    	}
    }

    int lower_bound_right(int a, int b, LL x, int k = 0, int l = 0, int r = -1) {
    	if (r == -1) r = st_siz;
    	if (ST_max[k] < x || r <= a || b <= l) return b;
    	else if (k >= st_siz - 1) return (k - (st_siz - 1));
    	else {
    		int v = lower_bound_right(a, b, x, 2 * k + 1, l, (l + r) / 2);
    		if (v != b) return v;
    		else {
    			return lower_bound_right(a, b, x, 2 * k + 2, (l + r) / 2, r);
    		}
    	}
    }
};

int main(){
	int N;
	cin >> N;
	vector<LL> P(N);
	rep(i,N) cin >> P[i];
	LL ans=0;
	SegmentTree ST(N);
	int siz=ST.get_size();
	rep(i,N) ST.max_update(i,P[i]);
	rep(i,N){
		LL p=P[i];
		LL l1=ST.lower_bound_left(0,i,p);
		LL l2=ST.lower_bound_left(0,l1,p);
		LL r1=ST.lower_bound_right(i+1,N,p);
		LL r2=ST.lower_bound_right(r1+1,N,p);
		if(l1==-1 && r1==N) continue;
		LL res=0;
		res+=(l1-l2)*(r1-i);
		res+=(r2-r1)*(i-l1);
		ans+=res*p;
	}
	cout << ans << endl;

	return 0;
}