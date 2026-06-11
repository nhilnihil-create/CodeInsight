#include <bits/stdc++.h>
#define ll long long int
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  D2(x)  cout << "[" << #x << ": "; for(auto it:x) cout << it << " "; cout << "]\n"; 
#define  D2p(x)	cout << #x << " ~ [ "; for(auto n: x) cout << n.first << "-" << n.second << " / "; cout << "]" << "\n";
#define vi vector<int> 
#define vll vector<ll> 
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " - " << x << endl;
const ll MOD = 1e9 + 7;
const ll INF = 1<<29;
const ll MAX_N = 2e5 + 7;
using namespace std;
int cel(int a,int b) { return ( (a / b) + ((a % b) != 0) ); }

ll bio(int n, int k) { 
	ll res = 1; 
	if (k > n - k) k = n - k;
	for (int i = 0; i < k; ++i) { 
		res *= (n - i); 
		res /= (i + 1); 
	} 
	return res; 
} 

int main() {
    IOS;
    int n; cin >> n;
    vi v(n);
    for(int i=0;i<n;++i) cin >> v[i];
    sort(all(v));
    ll sum = bio(n,3);
    // D2(v);
    for(int i=0;i<n-2;++i){
        for(int j=i+1;j<n-1;++j){
            int temp = v[i]+v[j];
            auto it = lower_bound(all(v),temp) - v.begin();
            sum -= (n - it);
        }
    }
    cout << sum;
}