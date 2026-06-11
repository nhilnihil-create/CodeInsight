#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;
const ll inf = 8e18;


int n, k;
int p[maxn];
ll c[maxn];

// -1,-2,10,10,-16 (we should end early)

ll solve(int start) {
    vector<ll> v;
    for (int x=p[start]; x!=start; x=p[x]) {
	v.push_back(c[x]);
    }
    v.push_back(c[start]);

    // watch(start);
    // for (int i: v) cout<<i<<",";
    // cout<<endl;
    
    int len = v.size();
    vector<ll> acc(len+1); //acc[i]: value after i moves
    for (int i=0; i<len; i++) {
	acc[i+1]=acc[i]+v[i];
    }
    ll res = -inf;

    // single loop
    for (int i=1; i<=min(k, len); i++) {
	res = max(res, acc[i]);
    }

    int loops = k/len;
    if (loops>0 && acc[len]>=0) {
	{
	    ll tail = 0;
	    for (int i=1; i<=(k-loops*len); i++) {
		tail = max(tail, acc[i]);
	    }
	    res = max(res, 1ll*loops*acc[len] + tail);
	}

	{
	    ll tail = 0;
	    for (int i=1; i<=min(len, k-(loops-1)*len); i++) {
		tail = max(tail, acc[i]);
	    }
	    res = max(res, 1ll*(loops-1)*acc[len] + tail);
	}
    }

    //cout<<start<<": "<<res<<endl;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    
    cin>>n>>k;
    for (int i=1; i<=n; i++) {
	cin>>p[i];
    }
    for (int i=1; i<=n; i++) {
	cin>>c[i];
    }

    ll ans = -inf;
    for (int i=1; i<=n; i++) {
	ans = max(ans, solve(i));
    }


    cout<<ans<<endl;    
    return 0;
}
