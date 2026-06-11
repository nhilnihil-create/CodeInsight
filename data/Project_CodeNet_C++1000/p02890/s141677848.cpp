#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << endl
#else
#define debug(x)
#endif
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

#define int long long

int N, C[300000] ={};
vector<int> v;
vector<int> sum;

int idx[300001];

signed main(){
	cin >> N;
	rep(i, N){
		int A;
		cin >> A;
		A--;
		C[A]++;
	}
	rep(i, N)
		if(C[i] != 0) v.pb(C[i]);
	sort(all(v));
	reverse(all(v));
	rep(i, v.size()){
		if(i > 0) sum.pb(sum.back()+v[i]);
		else sum.pb(v[i]);
	}
	int tmp = 0;
	for(int i=N; i>=0; i--){
		while(tmp < v.size() && v[tmp] > i) tmp++;
		idx[i] = tmp;
	}

	rep(i, N){
		if(v.size() <= i) cout << 0 << endl;
		else{
			int mainSum = sum[i];
			int subSum = N - sum[i];

			int ok = 0;
			int ng = N+1;
			while(ng-ok > 1){
				int m = (ok+ng)/2;
				int j = idx[m];
				if(j >= i+1){
					ok = m;
					continue;
				}
				int s = sum[i] - (j > 0 ? sum[j-1] : 0);
				int k = i+1-j;
				if(s+subSum >= m*k) ok = m;
				else ng = m;
				//cout << m << " " << j << " " << s << " " << k << endl;
			}
			cout << ok << endl;
		}
	}

}