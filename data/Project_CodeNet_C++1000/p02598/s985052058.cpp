#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int INF = 0x3f3f3f3f;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 45+10;
const int mod = 1e9+7;

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n,k,ans=0;

	cin >> n >> k;

	vi v(n);

	for(int &x:v) cin >> x;

	ll l=1,r=1e9+10,m;

	while(l <= r){
		m = (l+r)/2;
		int cnt=0;
		for(int i=0;i<n;++i){
			cnt+=(v[i]/m);
          	cnt-=(v[i]%m==0);
		}
		if(cnt<=k){
			ans=m;
			r=m-1;
		}
		else l = m+1;
	}

	cout << ans << endl;

    return 0;
}

