#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;


struct segment_tree {

    int fuck;
    bool mx;
    int merge(int x, int y) {
	if (mx) return max(x,y);
	return min(x,y);
	
    }
    ///////////////////////////////////
    int n;
    vector<int> t;
    segment_tree() {}
    void init(int n, int fuck=-1e9, bool mx=true) {
	this->n = n;
	this->fuck = fuck;
	this-> mx = mx;
	t.resize(4*n+10);
    }
    int get(int v, int tl, int tr, int l, int r) {
	if (l > tr || r < tl) {
	    return fuck;
	} else if (l <= tl && tr <= r) {
	    return t[v];
	} else {
	    int tm = (tl + tr)/2;
	    return merge(get(2*v, tl, tm, l, r), get(2*v+1, tm+1, tr, l, r));
	}
    }
    void update(int v, int tl, int tr, int idx, int val) {
	if (tl == tr) {
	    t[v] = val;
	} else {
	    int tm = (tl + tr)/2;
	    if (idx <= tm) {
		update(2*v, tl, tm, idx, val);
	    } else {
		update(2*v+1, tm+1, tr, idx, val);
	    }
	    t[v] = merge(t[2*v], t[2*v+1]);
	}
    
    }
};



int n;
int a[maxn];
ll ans;

int nl[maxn],nr[maxn];
int nl2[maxn], nr2[maxn];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }
    fill(nl,nl+n,-1); fill(nl2,nl2+n,-1);
    fill(nr,nr+n,n); fill(nr2,nr2+n,n);

    segment_tree tl;
    tl.init(n+10, -1e9, true);
    
    for (int i=1; i<=n; i++) {
	tl.update(1,1,n,i,-1e9);
    }
    
    for (int i=0; i<n; i++) {
	int j=i-1;
	while (j>=0 && a[i]>a[j]) {
	    j=nl[j];
	}
	nl[i]=j;

	if (nl[i] != -1) {
	    tl.update(1,1,n,a[nl[i]],-1e9);
	    int j2 = tl.get(1,1,n,a[i]+1,n);
	    if (j2 >= 0) {
		nl2[i] = j2;
	    }
	    tl.update(1,1,n,a[nl[i]],nl[i]);
	}
	tl.update(1,1,n,a[i],i);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    segment_tree tr; tr.init(n+10, 1e9, false);
    for (int i=1; i<=n; i++) {
	tr.update(1,1,n,i,1e9);
    }

    for (int i=n-1; i>=0; i--) {
	int j=i+1;
	while (j<n && a[i]>a[j]) {
	    j=nr[j];
	}
	nr[i]=j;

	if (nr[i] != n) {
	    tr.update(1,1,n,a[nr[i]],1e9);
	    int j2 = tr.get(1,1,n,a[i]+1,n);
	    if (j2 < n) {
		nr2[i] = j2;
	    }
	    tr.update(1,1,n,a[nr[i]],nr[i]);
	}
	tr.update(1,1,n,a[i],i);
    }


    for (int i=0; i<n; i++) {
	if (a[i] == n) continue;

	int L = nl[i];
	int R = nr[i];

	//cout<<L<<" "<<i<<" "<<R<<endl;

	ll x=0;

	if (L != -1) {
	    int Lp = nl2[i];
	    //Lp...L...i....R
	    ll cur = 1LL*(R-i)*(L-Lp);
	    x += cur;
	}

	if (R != n) {
	    int Rp = nr2[i];
	    //L....i....R....Rp
	    ll cur = 1LL*(Rp-R)*(i-L);
	    x += cur;
	}

	//cout<<a[i]<<": "<<x<<endl;
	
	ans += 1LL*a[i]*x;
    }

    cout<<ans<<endl;

    return 0;
}





// for (int i=0; i<n; i++) {
// 	for (int j=i+1; j<n; j++) {
// 	    vector<int> v;
// 	    for (int k=i; k<=j; k++) v.push_back(a[k]);
// 	    sort(v.rbegin(), v.rend());
// 	    ans += v[1];
// 	}
// }


// cout<<ans<<endl;
