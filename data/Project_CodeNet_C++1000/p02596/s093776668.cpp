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

	int k,v=7,ans=-1;
	
	cin >> k;

	for(int i=1;i<=1e6+10;++i){
		if(v%k==0){
			ans=i;
			break;
		}
		v = (v*10+7);
		v%=k;
	}

	cout << ans << endl;

    return 0;
}

