#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n, q;
ll t[maxn];

void upd(int i, ll dx) {
    for (; i<=n; i+=i&-i) {
	t[i] += dx;
    }
}


ll qry(int i) {
    ll res = 0;
    for (; i; i-=i&-i) {
	res += t[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>q;
    for (int i=1; i<=n; i++) {
	ll x; cin>>x;
	upd(i,x);
    }

    while (q--) {
	int t;
	cin>>t;
	if (t==0) {
	    int i,dx;
	    cin>>i>>dx;
	    i++;
	    upd(i,dx);
	} else {
	    int l,r;
	    cin>>l>>r;
	    l++;
	    cout<<qry(r)-qry(l-1)<<"\n";
	}
    }
    
    
    return 0;
}
