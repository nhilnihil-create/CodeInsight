#include<bits/stdc++.h>
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAXN = 3010; // Número máximo de ítens
const int MAXW = 3010; // Número máximo de peso carregado
int mt[MAXN+1][MAXW+1]; // Matríz global é iniciada com zeros

int knapSack(int w, int wt[], int val[], int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=w; j++){
			if(j==w)
				mt[i][j] = max(val[i-1]+mt[i-1][j-1], mt[i-1][j]);
			else if(wt[i-1]<=j)
				mt[i][j] = max(val[i-1]+mt[i-1][j-wt[i-1]], mt[i-1][j]);
			else
				mt[i][j] = mt[i-1][j];
		}
	}
	return mt[n][w];
}
int32_t main(){
	ios::sync_with_stdio(0);
	int n, t;
	cin >> n >> t;
	int wt[n], val[n];
	vector<ii> vs(n);
	for(auto &x:vs)
		cin >> x.ff >> x.ss;
	sort(all(vs));
	for(int i=0; i<n; ++i)
		wt[i]=vs[i].ff, val[i] = vs[i].ss;

	int ans = knapSack(t, wt, val, n);
	cout << ans << endl;
}
