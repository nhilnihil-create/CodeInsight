#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n;
ll a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }
    sort(a,a+n);

    priority_queue<ll> pq;
    ll res = 0;
    pq.push(a[n-1]);
    for (int i=n-2; i>=0; i--) {
	res += pq.top();
	//watch(res);
	pq.pop();
	pq.push(a[i]);
	pq.push(a[i]);
    }

    cout<<res<<endl;    
    return 0;
}
