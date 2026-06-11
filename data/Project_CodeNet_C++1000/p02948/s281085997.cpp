#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

class SegmentTree {
private:
    int n;
    vector<int> lo, hi, max_el; 

    void init(int i, int a, int b) {
        lo[i] = a;
        hi[i] = b;

        if (a == b) {
            return;
        }

        int m = (a+b)/2;
        init(2*i, a, m);
        init(2*i+1, m+1, b);
    }

    void update(int i, int a, int val) {
        if (lo[i] > a || hi[i] < a) {
            return;
        }

        if (lo[i] == hi[i] && hi[i] == a) {
            max_el[i] = val;
            return;
        }

        update(2*i, a, val);
        update(2*i + 1, a, val);
        max_el[i] = max(max_el[2*i], max_el[2*i+1]);
    }

    int maximum(int i, int a, int b) {
        if (lo[i] > b || hi[i] < a) {
            return -1;
        }

        if (lo[i] >= a && hi[i] <= b) {
            return max_el[i];
        }

        int left = maximum(2*i, a, b);
        int right = maximum(2*i + 1, a, b);
        return max(left, right);
    }
    
public:
    SegmentTree(int _n) : n(_n), lo(4*n+1), hi(4*n+1), max_el(4*n+1) {
        init(1,0,n-1);
    }

    // update value on one point to val
    void update(int a, int val) {
        update(1, a, val);
    }
    int maximum(int a, int b) {
        return maximum(1, a, b);
    }
};
 
int main () {
	int N, M;
    cin >> N >> M;
	vector<pii> v(N);
    int a, b;
	rep(i,N) {
		cin >> a >> b;
        v[i] = make_pair(b,a);
	}
    sort(v.begin(), v.end());
    SegmentTree st(M+1);
    rep(i,M+1) {
        st.update(i,i);
    }
	int ans = 0;
    rep(i,N) {
        int a = v[N-1-i].second;
        int b = v[N-1-i].first;
        int ind = st.maximum(0, M-a);
        if (ind == -1)
            continue;
        ans += b;
        st.update(ind, -1);        
    }
	cout << ans << endl;
    return 0;
}